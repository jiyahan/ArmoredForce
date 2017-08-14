#include "CAppleSignal.h"


atom::CAppleSignal::CAppleSignal() : 
state(false)
{
    #ifdef __APPLE__
    pthread_mutex_init( & region, NULL );
    pthread_cond_init ( & signal, NULL );
    #endif
}

atom::CAppleSignal::CAppleSignal(const char * name) : 
state(false)
{
    UNREFERENCED_PARAMETER(name);

    #ifdef __APPLE__
    pthread_mutex_init( & region, NULL );
    pthread_cond_init ( & signal, NULL );
    #endif
}

atom::CAppleSignal::~CAppleSignal() 
{
    #ifdef __APPLE__
    pthread_cond_destroy ( & signal );
    pthread_mutex_destroy( & region );
    #endif
}

bool atom::CAppleSignal::Reset() 
{
    #ifdef __APPLE__
    pthread_mutex_lock  ( & region );   state = false;
    pthread_mutex_unlock( & region );
    #endif
    return true;
}

bool atom::CAppleSignal::Awake() 
{
    #ifdef __APPLE__
    pthread_mutex_lock    ( & region ); state = true;
    pthread_mutex_unlock  ( & region );
    pthread_cond_broadcast( & signal );
    #endif
    return true;
}

bool atom::CAppleSignal::Await(U64 timeout) 
{
    bool result = false;

    #ifdef __APPLE__
    
	if( timeout == U64(INFINITE) )
    {
        pthread_mutex_lock  ( & region );
        while( (result = state) == false ) pthread_cond_wait( & signal, & region );
        pthread_mutex_unlock( & region );
    }
    else
    {
        // ����ʱ�䣬��׼�������ٽ�����
        timeval now;
        if( gettimeofday(& now, NULL) == 0 )
        {
            timespec end;
            end.tv_sec  = now.tv_sec + timeout / 1000;
            end.tv_nsec = now.tv_usec * 1000 + ( timeout % 1000 ) * 1000000;
            if( end.tv_nsec > 1000000000 ) 
            {
                end.tv_sec  ++;
                end.tv_nsec -= 1000000000;
            }

            pthread_mutex_lock  ( & region );            
            while( (result = state) == false )
            {
                // ��ʱ�ȴ����������0�����ʾ�������������������ֵ���㣬���ʾ����
                int ret = pthread_cond_timedwait( & signal, & region, & end );
                if( ret == ETIMEDOUT ) break;
                else
                if( ret != 0 )
                {
                    printf( "error:%s.\n", strerror(ret) );
                    break;
                }
            }
            pthread_mutex_unlock( & region );
        }        
    }

    #else
    UNREFERENCED_PARAMETER( timeout );
    #endif

    return result;
}
