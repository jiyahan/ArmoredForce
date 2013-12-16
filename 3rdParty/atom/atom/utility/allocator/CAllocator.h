#ifndef CALLOCATOR_H
#define CALLOCATOR_H
//Begin section for file CAllocator.h
//TODO: Add definitions that you want preserved
//End section for file CAllocator.h
#include "CAllocatorQueue.h"



namespace atom
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T, size_t A = 100, size_t Q = 16>
    class CAllocator
    {

        //Begin section for atom::CAllocator
        //TODO: Add attributes that you want preserved
        //End section for atom::CAllocator

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CAllocatorQueue<T, A> queues[Q];



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile size_t allocate;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile size_t released;




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CAllocator(): 
            allocate(0),released(0)
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CAllocator()
            {
                //TODO Auto-generated method stub
                Shutdown();
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  Initiate()
            {
                //TODO Auto-generated method stub
                return true;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  Shutdown()
            {
                //TODO Auto-generated method stub
			    T* object( NULL );
			    for( size_t i = 0; i < Q; ++ i )
			    {
                    while( NULL != ( object = queues[i].Get() ) ) {
                        SAFE_DELETE( object );
                    }
			    }
                return true;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline T *  Allocate()
            {
                //TODO Auto-generated method stub
                // 首先从队列内获取对象，如果没有获取到对象，则准备创建一个对象；
		        T* result( NULL );
                if( NULL == ( result = 
                    queues[allocate ++ % Q].Get() ) ) {
                    result = new T;
                }
		        return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void  Released(T * object)
            {
                //TODO Auto-generated method stub
                // 首先尝试放入队列内；
                if( object && false == 
                    queues[released -- % Q].Put(object) ) {
                    delete object;
                }
            }

    };  //end class CAllocator



} //end namespace atom



#endif
