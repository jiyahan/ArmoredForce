#ifndef CLINUXCRITICALSECTION_H
#define CLINUXCRITICALSECTION_H

#include "../../Common.h"


namespace atom
{



    class CLinuxCriticalSection
    {


        
        private:
            #ifdef __linux
            pthread_mutex_t mutex;
            #endif



        public:

            inline CLinuxCriticalSection()
            {
                #ifdef __linux    
                // ׼�������������Զ��������߳����롣
                pthread_mutexattr_t attr;
                pthread_mutexattr_init   ( & attr );
                pthread_mutexattr_settype( & attr, PTHREAD_MUTEX_RECURSIVE );
        
                // ��ʼ���������������ٻ����������Զ���
                pthread_mutex_init( & mutex, & attr );
                pthread_mutexattr_destroy( & attr );
                #endif
            }



            inline ~CLinuxCriticalSection()
            {
                #ifdef __linux
                pthread_mutex_destroy( & mutex );
                #endif
            }



            inline void Enter()
            {
                #ifdef __linux
                pthread_mutex_lock( & mutex );
                #endif
            }



            inline bool TryEnter()
            {
                #ifdef __linux
                return( pthread_mutex_trylock( & mutex ) == 0 );
                #else
                return false;
                #endif
            }



            inline void Leave()
            {
                #ifdef __linux
                pthread_mutex_unlock( & mutex );
                #endif
            }



    };  //end class CLinuxCriticalSection


}//end namespace atom


#endif
