#ifndef TAGMEMORYSECTOR_H
#define TAGMEMORYSECTOR_H
//Begin section for file tagMemorySector.h
//TODO: Add definitions that you want preserved
//End section for file tagMemorySector.h
#include "../../Common.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    struct tagMemorySector
    {

        //Begin section for atom::tagMemorySector
        //TODO: Add attributes that you want preserved
        //End section for atom::tagMemorySector

        public:


            //<p>memory length</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            size_t level;



            //<p>memory capacity</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            size_t limit;



            //<p>user data length</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            size_t valid;



            //<p>reference counter</p>
			#ifdef _WIN32
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile long refer;
			#endif

			#if defined(__linux) || defined(__APPLE__)
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile int  refer;
			#endif



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagMemorySector(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline int IncRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline int DecRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline int GetRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Reset(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Reset(size_t valid); 

	
	
	};  //end struct tagMemorySector


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemorySector::tagMemorySector() : 
level(0),limit(0),valid(0),refer(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::tagMemorySector::IncRef() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    return InterlockedIncrement( &refer);
    #endif

    #if defined(__linux) || defined(__APPLE__)
    return __sync_add_and_fetch( &refer, 1 );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::tagMemorySector::DecRef() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    return InterlockedDecrement( &refer );
    #endif

    #if defined(__linux) || defined(__APPLE__)
    return __sync_sub_and_fetch( &refer, 1 );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::tagMemorySector::GetRef() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    return InterlockedCompareExchange ( &refer, 0, 0 );
    #endif

    #if defined(__linux) || defined(__APPLE__)
    return __sync_val_compare_and_swap( &refer, 0, 0 );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagMemorySector::Reset() 
{
    //TODO Auto-generated method stub
    // clear user data length
    valid = 0;

    #ifdef _WIN32
    InterlockedExchange( &refer, 0 );
    #endif

    #if defined(__linux) || defined(__APPLE__)
    __sync_lock_release( &refer );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagMemorySector::Reset(size_t align)
{
    //TODO Auto-generated method stub
    level = align;
    limit = align - sizeof( tagMemorySector );
    refer = 0;
    valid = 0;
}

#endif
