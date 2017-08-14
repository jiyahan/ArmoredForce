#include "CCallStack.h"
//Begin section for file CCallStack.cpp
//TODO: Add definitions that you want preserved
//End section for file CCallStack.cpp



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CCallStack::Initiate() 
{
    //TODO Auto-generated method stub
    bool result = true;

	#if defined(_WIN32)
	if( FALSE == 
        SymInitialize( GetCurrentProcess(), NULL, TRUE ) )
    {
        result = false;
        //si::CAnsiLog log;
        //log <<  "Initiate Dbghelp FAILED." << si::end_error;
    }
	#elif defined(__linux) || defined(__APPLE__)
	// linux apple����Ҫ��ʼ����
	#endif

	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CCallStack::Shutdown() 
{
    //TODO Auto-generated method stub
	#if defined(_WIN32)
    if( FALSE ==
        SymCleanup( GetCurrentProcess() ) )
    {
        //si::CAnsiLog log;
        //log <<  "Shutdown Dbghelp FAILED." << si::end_error;
    }
	#elif defined(__linux) || defined(__APPLE__)
	// linux����Ҫ���ջ���
	#endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CCallStack::RecordCallStack(a_string & stack) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( stack );

	#if defined(_WIN32)

    HANDLE process = GetCurrentProcess();
    HANDLE thread  = GetCurrentThread ();

    CONTEXT context;
	memset( & context, 0, sizeof(context) );
	RtlCaptureContext( & context );

    STACKFRAME sf;
    memset( & sf, 0, sizeof(STACKFRAME) );

    #if defined(_AMD64_)
    
    sf.AddrPC.Offset    = context.Rip;
    sf.AddrPC.Mode      = AddrModeFlat;
    sf.AddrStack.Offset = context.Rsp;
    sf.AddrStack.Mode   = AddrModeFlat;
    sf.AddrFrame.Offset = context.Rbp;
    sf.AddrFrame.Mode   = AddrModeFlat;
    DWORD machineType   = IMAGE_FILE_MACHINE_AMD64;

    #elif defined(_IA64_)

    sf.AddrPC.Offset    = context.Rip;
    sf.AddrPC.Mode      = AddrModeFlat;
    sf.AddrStack.Offset = context.Rsp;
    sf.AddrStack.Mode   = AddrModeFlat;
    sf.AddrFrame.Offset = context.Rbp;
    sf.AddrFrame.Mode   = AddrModeFlat;
    DWORD machineType   = IMAGE_FILE_MACHINE_IA64;

    #elif defined(_X86_)

    sf.AddrPC.Offset    = context.Eip;
    sf.AddrPC.Mode      = AddrModeFlat;
    sf.AddrStack.Offset = context.Esp;
    sf.AddrStack.Mode   = AddrModeFlat;
    sf.AddrFrame.Offset = context.Ebp;
    sf.AddrFrame.Mode   = AddrModeFlat;
    DWORD machineType   = IMAGE_FILE_MACHINE_I386;

    #endif

    for(;;)
    {
        #if defined(_AMD64_) || defined(_IA64_)
        if( !StackWalk64(machineType, process, thread, & sf, & context, 0, SymFunctionTableAccess, SymGetModuleBase, 0) )
        {
            break;
        }
        #elif defined(_X86_)
        if( !StackWalk  (machineType, process, thread, & sf, & context, 0, SymFunctionTableAccess, SymGetModuleBase, 0) )
        {
            break;
        }
        #endif

        if( sf.AddrFrame.Offset == 0 )
        {
            break;
        }

        BYTE symbolBuffer[sizeof(SYMBOL_INFO) + 1024];
        memset( symbolBuffer, 0, sizeof(symbolBuffer) );

        PSYMBOL_INFO pSymbol = reinterpret_cast<PSYMBOL_INFO>( symbolBuffer );
        pSymbol -> SizeOfStruct = sizeof( SYMBOL_INFO );
        pSymbol -> MaxNameLen   = 1024;

        if( SymFromAddr(process, sf.AddrPC.Offset, 0, pSymbol) )
        {
            char temp[64];
    
            #if defined(_AMD64_) || defined(_IA64_)
            sprintf( temp, "0x%016X ", pSymbol -> Address );
            #elif defined(_X86_)
            sprintf( temp, "0x%08X " , pSymbol -> Address );
            #endif

            stack += temp;
            if( pSymbol -> Name ){ stack += pSymbol -> Name; 
            }
            stack += "\r\n";
        }
    }

	#elif defined(__linux) || defined(__APPLE__)

	// under linux, you must add -rdynamic link option, else you can't watch the 
	// call stack function name.

	// ��buffer�е�ָ��ʵ���ǴӶ�ջ�л�ȡ�ķ��ص�ַ��ÿһ����ջ�����һ�����ص�ַ��
	// ע��ĳЩ���������Ż�ѡ��Ի�ȡ��ȷ�ĵ��ö�ջ�и��ţ�������������û�ж�ջ���
	// ɾ�����ָ��Ҳ��ʹ�޷���ȷ������ջ���ݣ�
    #define BACK_TRACE 4096

	void* buffer[BACK_TRACE]; 
	memset( buffer, 0, sizeof(buffer) );
	int size = backtrace( buffer, BACK_TRACE );
		
	// ��ȡ��ջ��ָ�룻
	// ֻ��ʹ��ELF��ExecuELFtable and linking Format�������Ƹ�ʽ�ĳ�����ܻ�ȡ����
	// ���ƺ�ƫ�Ƶ�ַ��������ϵͳ,ֻ��16���Ƶķ��ص�ַ�ܱ���ȡ�����⣬�������Ҫ��
	// ����Ӧ�ı�־��������������֧�ֺ��������ܣ���ʹ��GNU ld��ϵͳ�У�����Ҫ����
	// -rdynamic ��־����

	char** functions = backtrace_symbols( buffer, size );
		
	// �����ȡ�ɹ������ӡ������
	if( functions )
	{
		for( int i = 0; i < size; ++ i ) 
		{
			if( functions[i] ) {
				stack += functions[i];
				stack += "\r\n";
			}
		}
		free( functions );
	}
	#endif
    
	return 0;
}
