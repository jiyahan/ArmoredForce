#include "CAppleThread.h"
//Begin section for file CAppleThread.cpp
//TODO: Add definitions that you want preserved
//End section for file CAppleThread.cpp


#ifdef __APPLE__
void * _AppleEntry(void * argument)
{
    U32 result = 0;
    atom::CAppleThread * implement = 
        reinterpret_cast<atom::CAppleThread *>( argument );
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


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleThread::CAppleThread(const char * name) :
#ifdef __APPLE__
handle(0), 
#endif
signal("thread")
{
    //TODO Auto-generated method stub
    if( name ) thread = name;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CAppleThread::~CAppleThread() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CAppleThread::GetName() 
{
    //TODO Auto-generated method stub
    return thread.c_str();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleThread::CloseNotify() 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    signal.Awake();
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleThread::Begin(U08 priority) 
{
    //TODO Auto-generated method stub
    bool result = false;

    #ifdef __APPLE__
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

        if( pthread_create(& handle, & attr, _AppleEntry, this) == 0 )
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleThread::Close(U64 timeout) 
{
    //TODO Auto-generated method stub
    bool result = false;

    #ifdef __APPLE__
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleThread::OnThreadBegin() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CAppleThread::OnThreadClose() 
{
    //TODO Auto-generated method stub
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CAppleThread::Run() 
{
    //TODO Auto-generated method stub
	return 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CAppleThread::Sleep(U64 milisecond) 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    usleep( static_cast<useconds_t>(milisecond * 1000) );
    #else
    UNREFERENCED_PARAMETER( milisecond );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CAppleThread::GetCurrentThreadID() 
{
    //TODO Auto-generated method stub
    #ifdef __APPLE__
    return reinterpret_cast<U64>( pthread_self() );
    #else
    return 0;
    #endif
}
