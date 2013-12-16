#ifndef CALLOCATORQUEUE_H
#define CALLOCATORQUEUE_H
//Begin section for file CAllocatorQueue.h
//TODO: Add definitions that you want preserved
//End section for file CAllocatorQueue.h
#include "CAllocatorQueueBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../tool/CCriticalSectionScope.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T, size_t A = 100>
    class CAllocatorQueue
    {

        //Begin section for atom::CAllocatorQueue
        //TODO: Add attributes that you want preserved
        //End section for atom::CAllocatorQueue

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typename CAllocatorQueueBind<T>::type objects;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection section;




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CAllocatorQueue()
            {
                //TODO Auto-generated method stub
                CCriticalSectionScope scope( section );
                objects.reserve( A );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CAllocatorQueue()
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline T *  Get()
            {
                //TODO Auto-generated method stub
		        T* result = NULL;
                section.Enter();
		        if( !objects.empty() ) {
                    result = objects.back();
			        objects.pop_back();
		        }
                section.Leave();
		        return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  Put(T * object)
            {
                //TODO Auto-generated method stub
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
