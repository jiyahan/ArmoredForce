#ifndef CALLOCATORQUEUE_H
#define CALLOCATORQUEUE_H
#include "CAllocatorQueueBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../tool/CCriticalSectionScope.h"



namespace atom
{



    template <class T, size_t A = 100>
    class CAllocatorQueue
    {


        private:


            typename CAllocatorQueueBind<T>::type objects;



            CCriticalSection section;




        public:


            inline CAllocatorQueue()
            {
                CCriticalSectionScope scope( section );
                objects.reserve( A );
            }


            inline virtual ~CAllocatorQueue()
            {
            }


            inline T *  Get()
            {
		        T* result = NULL;
                section.Enter();
		        if( !objects.empty() ) {
                    result = objects.back();
			        objects.pop_back();
		        }
                section.Leave();
		        return result;
            }


            inline bool  Put(T * object)
            {
                if( !object ) return false;

		        bool result = false;
                section.Enter();
				result = ( objects.size() < A );
                if( result ) {
                    objects.push_back( object );
			    }
                section.Leave();
		        return result;
            }

    };  //end class CAllocatorQueue



} //end namespace atom



#endif
