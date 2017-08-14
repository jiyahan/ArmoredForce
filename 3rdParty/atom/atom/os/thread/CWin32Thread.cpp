#include "CWin32Thread.h"
#include "../callstack/CCallStack.h"
#include "../timer/CSystemTimer.h"
#include "../../utility/stl/a_string.h"



#ifdef _WIN32

// ���ʹ�õı�������VC������crash dump���ܡ�
int RecordException(const char * value, PEXCEPTION_POINTERS information)
{
    atom::a_string filename, textname;

    // ��ȡϵͳʱ�䣻
    atom::a_string timer;
    atom::CSystemTimer::TimeToString( atom::CSystemTimer::Now(), timer );

    for( atom::a_string::iterator 
        it = timer.begin(); it != timer.end(); ++ it ) {
        if( *it == ':' ) *it = '-';
    }

    // ׼��dmp�ļ���log�ļ�����
    filename = "crash";
	if( value ) { 
	filename += " "; filename += value; }
    filename += " "; filename += timer; 

    // ��¼���ö�ջ��
    textname = filename;
    textname += ".log"; filename += ".dmp";

    // �����ļ���׼����¼dmp��
	HANDLE hFile = CreateFileA(
		filename.c_str(),
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH,
		NULL );

	MINIDUMP_EXCEPTION_INFORMATION except;
	except.ThreadId	         = GetCurrentThreadId();
	except.ExceptionPointers = information;
	except.ClientPointers    = FALSE;

	MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile,
		MiniDumpNormal,
		information ? & except : NULL, NULL, NULL);

    CloseHandle( hFile ); hFile = NULL;

    // ��ȡ���ö�ջ��
    atom::a_string callstack;
    atom::CCallStack::RecordCallStack( callstack );

    // ��¼���ö�ջ��
    FILE * file = fopen( textname.c_str(), "w+" );
    if( file ) {
        fprintf( file, "%s", callstack.c_str() );
        fclose ( file );
    }

    // ���������쳣������
    return EXCEPTION_CONTINUE_SEARCH;
}

unsigned __stdcall _Win32Entry(LPVOID argument)
{
    unsigned int result = 0;
    atom::CWin32Thread* implement = 
        reinterpret_cast<atom::CWin32Thread*>( argument );
    if( implement )
    {
        // �ı��̵߳����֣����ڵ��ԣ�
        struct tagTHREADNAME_INFO
        {
            DWORD  dwType;     // must be 0x1000
            LPCSTR szName;     // pointer to name (in user addr space)
            DWORD  dwThreadID; // thread ID (-1=caller thread)
            DWORD  dwFlag;     // reserved for future use, must be zero
        };

        // ���ṹ�壻
        tagTHREADNAME_INFO info;
        info.dwType     = 0x1000;
        info.szName     = implement -> GetName();
        info.dwThreadID = (DWORD)-1;
        info.dwFlag     = 0;

        // ���� Windows ƽ̨���е� 0x406D1388 �쳣�����߳�����
        __try 
        {
            RaiseException( 0x406D1388, 0, sizeof(info) / sizeof(DWORD), (ULONG_PTR*)&info ); 
        } 
        __except( EXCEPTION_CONTINUE_EXECUTION ) 
        {
        }

        __try
        {
            result = implement -> Run();
        }
        __except( RecordException( implement -> GetName(), GetExceptionInformation() ) ) 
        {
        }
        implement -> OnThreadClose();
    }

    // �������˳��̣߳��������ر�handle
    _endthreadex( result ); 
    return result;
}

#endif

atom::CWin32Thread::CWin32Thread(const char * name) : 
handle(NULL)
{
    if( name ) thread = name;
}

atom::CWin32Thread::~CWin32Thread() 
{
}

const char * atom::CWin32Thread::GetName() 
{
    return thread.c_str();
}

bool atom::CWin32Thread::Begin(U08 priority) 
{
    bool result = false;

    #ifdef _WIN32
    region.Enter();
    if( handle == NULL )
    {
        U32 id = 0;
        handle = reinterpret_cast<HANDLE>( 
            _beginthreadex(NULL, 0, &_Win32Entry, this, 0, &id) );
        if( handle )
        {
            // ���ʧ�ܣ�������5���ڹر��̡߳�
            result = OnThreadBegin();

            // ����ɹ������޸��߳����ȼ���
            if( result )
            {
                switch( priority )
                {
                case TP_LOWEST:
                    result = ( TRUE == 
                        SetThreadPriority(handle, THREAD_PRIORITY_LOWEST) );
                    break;
                case TP_BELOW_NORMAL:
                    result = ( TRUE == 
                        SetThreadPriority(handle, THREAD_PRIORITY_BELOW_NORMAL) );
                    break;
                case TP_NORMAL:
                    // ȱʡ���߳����ȼ������ı䣻
                    break;
                case TP_ABOVE_NORMAL:
                    result = ( TRUE == 
                        SetThreadPriority(handle, THREAD_PRIORITY_HIGHEST) );
                    break;
                case TP_HIGHEST:
                    result = ( TRUE == 
                        SetThreadPriority(handle, THREAD_PRIORITY_TIME_CRITICAL) );
                    break;
                }
            }

            // ���ʧ�ܣ���׼�������̣߳�
            if( result == false ) 
            {
                DWORD error = GetLastError();
                printf( "Failed change thread priority: %lu\n.", error );
                Close( 5000 );
            }
        }
    }
    region.Leave();

    #else

    UNREFERENCED_PARAMETER( priority );
    #endif

    return result;
}

bool atom::CWin32Thread::Close(U64 timeout) 
{

    #ifdef _WIN32
    region.Enter();
    if( handle != NULL )
    {
        // ���ȳ��Եȴ��߳����йرա�
        bool terminateThread = false;
        switch( WaitForSingleObject( handle, static_cast<DWORD>(timeout) ) )
        {
        case WAIT_OBJECT_0:
            break;
        case WAIT_TIMEOUT:
            terminateThread = true;
            break;
        default:
            terminateThread = true;
            printf( "Thread failed to end. Error code: %d\n", static_cast<int>( GetLastError() ) );
            break;
        }

        // �����Ҫǿ�ƹر��̣߳�����ǿ�ƹر��̡߳�
        if( terminateThread ) 
        {
            if( TerminateThread(handle, 1) == FALSE ) {
                OutputDebugString( "Failed to terminate thread.\n" );
            }
            OnThreadClose();
        }

        // �رվ����
        CloseHandle( handle ); handle = NULL;
    }
    region.Leave();

    #else

    UNREFERENCED_PARAMETER( timeout );
    #endif

    return true;
}

bool atom::CWin32Thread::OnThreadBegin() 
{
    return true;
}

bool atom::CWin32Thread::OnThreadClose() 
{
    return true;
}

U32 atom::CWin32Thread::Run() 
{
    return 0;
}

void atom::CWin32Thread::Sleep(U64 milisecond) 
{
    #ifdef _WIN32
    ::Sleep( static_cast<DWORD>(milisecond) );
    #else
    UNREFERENCED_PARAMETER( milisecond );
    #endif
}

U64 atom::CWin32Thread::GetCurrentThreadID() 
{
    #ifdef _WIN32
    return ::GetCurrentThreadId();
    #else
    return 0;
    #endif
}
