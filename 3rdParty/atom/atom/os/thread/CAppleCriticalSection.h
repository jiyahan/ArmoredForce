#ifndef CAPPLECRITICALSECTION_H
#define CAPPLECRITICALSECTION_H
//Begin section for file CAppleCriticalSection.h
//TODO: Add definitions that you want preserved
//End section for file CAppleCriticalSection.h

#include "../../Common.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CAppleCriticalSection
    {
        //Begin section for atom::CAppleCriticalSection
        //TODO: Add attributes that you want preserved
        //End section for atom::CAppleCriticalSection


        
        private:
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            #ifdef __APPLE__
            pthread_mutex_t mutex;
            #endif



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CAppleCriticalSection()
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CAppleCriticalSection()
            {
                //TODO Auto-generated method stub
				#ifdef __APPLE__
                pthread_mutex_destroy( & mutex );
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Enter()
            {
                //TODO Auto-generated method stub
				#ifdef __APPLE__
                pthread_mutex_lock( & mutex );
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool TryEnter()
            {
                //TODO Auto-generated method stub
				#ifdef __APPLE__
                return( pthread_mutex_trylock( & mutex ) == 0 );
                #else
                return false;
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Leave()
            {
                //TODO Auto-generated method stub
				#ifdef __APPLE__
                pthread_mutex_unlock( &mutex );
                #endif
            }



    };  //end class CAppleCriticalSection


}//end namespace atom


#endif
