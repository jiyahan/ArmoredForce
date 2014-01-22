#ifndef CAPPLECRITICALSECTION_H
#define CAPPLECRITICALSECTION_H

#include "../../Common.h"


namespace atom
{



    class CAppleCriticalSection
    {


        
        private:
            #ifdef __APPLE__
            pthread_mutex_t mutex;
            #endif



        public:

            inline CAppleCriticalSection()
            {
				#ifdef __APPLE__
                // 准备互斥锁的属性对象，允许线程重入。
                pthread_mutexattr_t attr;
                pthread_mutexattr_init   ( & attr );
                pthread_mutexattr_settype( & attr, PTHREAD_MUTEX_RECURSIVE );
        
                // 初始化互斥锁对象，销毁互斥锁的属性对象。
                pthread_mutex_init( & mutex, & attr );
                pthread_mutexattr_destroy( & attr );    
                #endif
            }



            inline ~CAppleCriticalSection()
            {
				#ifdef __APPLE__
                pthread_mutex_destroy( & mutex );
                #endif
            }



            inline void Enter()
            {
				#ifdef __APPLE__
                pthread_mutex_lock( & mutex );
                #endif
            }



            inline bool TryEnter()
            {
				#ifdef __APPLE__
                return( pthread_mutex_trylock( & mutex ) == 0 );
                #else
                return false;
                #endif
            }



            inline void Leave()
            {
				#ifdef __APPLE__
                pthread_mutex_unlock( &mutex );
                #endif
            }



    };  //end class CAppleCriticalSection


}//end namespace atom


#endif
