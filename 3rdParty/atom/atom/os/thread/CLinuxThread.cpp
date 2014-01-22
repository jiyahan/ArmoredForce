#include "CLinuxThread.h"


#ifdef __linux
void * _LinuxEntry(void * argument)
{
    U32 result = 0;
    atom::CLinuxThread * implement = 
        reinterpret_cast<atom::CLinuxThread *>( argument );
    if( implement ) 
    {
        result = 
        implement -> Run();
        implement -> CloseNotify();
        implement -> OnThreadClose();
    }

    pthread_exit( (void *)result );
    return NULL;
}
#endif

atom::CLinuxThread::CLinuxThread(const char * name) :
#ifdef __linux
handle(0), 
#endif
signal("thread")
{
    if( name ) thread = name;
}

atom::CLinuxThread::~CLinuxThread() 
{
}

const char * atom::CLinuxThread::GetName() 
{
    return thread.c_str();
}

void atom::CLinuxThread::CloseNotify() 
{
    #ifdef __linux
    signal.Awake();
    #endif
}

bool atom::CLinuxThread::Begin(U08 priority) 
{
    bool result = false;

    #ifdef __linux
    region.Enter();
    if( handle == 0 )
    {
        // 首先重置信号，然后开始创建线程。
        signal.Reset();

		int min_priority = sched_get_priority_min( SCHED_RR );
		int max_priority = sched_get_priority_max( SCHED_RR );

		struct sched_param para; 

		switch( priority )
		{
        case TP_LOWEST:
			para.sched_priority = min_priority; 
            break;
        case TP_BELOW_NORMAL:
			para.sched_priority = ( min_priority + max_priority ) / 4; 
            break;
        case TP_NORMAL:
			para.sched_priority = ( min_priority + max_priority ) / 2; 
            break;
        case TP_ABOVE_NORMAL:
			para.sched_priority = ( min_priority + max_priority ) * 3 / 4; 
            break;
        case TP_HIGHEST:
			para.sched_priority = max_priority; 
            break;
		}

		pthread_attr_t attr; 
		pthread_attr_init( & attr ); 
		pthread_attr_setinheritsched( & attr, PTHREAD_EXPLICIT_SCHED );
		pthread_attr_setschedpolicy ( & attr, SCHED_RR );
		pthread_attr_setschedparam  ( & attr, & para );

        if( pthread_create(& handle, & attr, _LinuxEntry, this) == 0 )
        {

            // 如果失败，则尝试在5秒内关闭线程。
            if( ( result = OnThreadBegin() ) == false ) {
                Close( 5000 );
            }
        }

		pthread_attr_destroy( & attr );
    }
    region.Leave();
    #else

    UNREFERENCED_PARAMETER( priority );
    #endif

    return result;
}

bool atom::CLinuxThread::Close(U64 timeout) 
{
    bool result = false;

    #ifdef __linux
    region.Enter();
    if( handle )
    {
        // 如果是超时，则强制关闭线程。
        if( signal.Await(timeout) == false ) {
            pthread_cancel( handle ); OnThreadClose();
        }
        // 执行线程的结束操作。
        result = true; handle = 0;
    }
    region.Leave();
    #else

    UNREFERENCED_PARAMETER(timeout);
    #endif

    return result;
}

bool atom::CLinuxThread::OnThreadBegin() 
{
    return true;
}

bool atom::CLinuxThread::OnThreadClose() 
{
    return true;
}

U32 atom::CLinuxThread::Run() 
{
    return 0;
}

void atom::CLinuxThread::Sleep(U64 milisecond) 
{
    #ifdef __linux
    usleep( static_cast<useconds_t>(milisecond * 1000) );
    #else
    UNREFERENCED_PARAMETER( milisecond );
    #endif
}
U64 atom::CLinuxThread::GetCurrentThreadID() 
{
    #ifdef __linux
    return pthread_self();
    #else
    return 0;
    #endif
}
