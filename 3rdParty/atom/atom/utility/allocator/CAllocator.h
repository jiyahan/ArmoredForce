#ifndef CALLOCATOR_H
#define CALLOCATOR_H
#include "CAllocatorQueue.h"



namespace atom
{
    


    template <class T, size_t A = 100, size_t Q = 16>
    class CAllocator
    {


        private:


            CAllocatorQueue<T, A> queues[Q];



            volatile size_t allocate;



            volatile size_t released;




        public:


            inline CAllocator(): 
            allocate(0),released(0)
            {
            }


            inline virtual ~CAllocator()
            {
                Shutdown();
            }


            inline bool  Initiate()
            {
                return true;
            }


            inline bool  Shutdown()
            {
			    T* object( NULL );
			    for( size_t i = 0; i < Q; ++ i )
			    {
                    while( NULL != ( object = queues[i].Get() ) ) {
                        SAFE_DELETE( object );
                    }
			    }
                return true;
            }


            inline T *  Allocate()
            {
                // 首先从队列内获取对象，如果没有获取到对象，则准备创建一个对象；
		        T* result( NULL );
                if( NULL == ( result = 
                    queues[allocate ++ % Q].Get() ) ) {
                    result = new T;
                }
		        return result;
            }


            inline void  Released(T * object)
            {
                // 首先尝试放入队列内；
                if( object && false == 
                    queues[released -- % Q].Put(object) ) {
                    delete object;
                }
            }

    };  //end class CAllocator



} //end namespace atom



#endif
