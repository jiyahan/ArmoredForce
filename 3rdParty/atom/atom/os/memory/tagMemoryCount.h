#ifndef TAGMEMORYCOUNT_H
#define TAGMEMORYCOUNT_H
//Begin section for file tagMemoryCount.h
//TODO: Add definitions that you want preserved
//End section for file tagMemoryCount.h
#include "../../Common.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    struct tagMemoryCount
    {

        //Begin section for atom::tagMemoryCount
        //TODO: Add attributes that you want preserved
        //End section for atom::tagMemoryCount

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile long a_count;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile long r_count;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            volatile long m_count;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagMemoryCount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~tagMemoryCount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Reset(long & a, long & r, long & m); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void IncACount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void IncRCount(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void IncMCount(); 



    };  //end struct tagMemoryCount


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemoryCount::tagMemoryCount() : 
a_count(0),r_count(0),m_count(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemoryCount::~tagMemoryCount() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagMemoryCount::Reset(long & a, long & r, long & m) 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    a = InterlockedExchange( & a_count, 0 );
    r = InterlockedExchange( & r_count, 0 );
    m = InterlockedExchange( & m_count, 0 );
    #endif

    #ifdef __linux
    a = __sync_lock_test_and_set( & a_count, 0 );
    r = __sync_lock_test_and_set( & r_count, 0 );
    m = __sync_lock_test_and_set( & m_count, 0 );
    #endif

    #ifdef __APPLE__
    a = __sync_lock_test_and_set( & a_count, 0 );
    r = __sync_lock_test_and_set( & r_count, 0 );
    m = __sync_lock_test_and_set( & m_count, 0 );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagMemoryCount::IncACount() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    InterlockedIncrement( & a_count);
    #endif

    #ifdef __linux
    __sync_add_and_fetch( & a_count, 1 );
    #endif

    #ifdef __APPLE__
    __sync_add_and_fetch( & a_count, 1 );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagMemoryCount::IncRCount() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    InterlockedIncrement( & r_count);
    #endif

    #ifdef __linux
    __sync_add_and_fetch( & r_count, 1 );
    #endif

	#ifdef __APPLE__
    __sync_add_and_fetch( & r_count, 1 );
    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::tagMemoryCount::IncMCount() 
{
    //TODO Auto-generated method stub
    #ifdef _WIN32
    InterlockedIncrement( & m_count);
    #endif

    #ifdef __linux
    __sync_add_and_fetch( & m_count, 1 );
    #endif

	#ifdef __APPLE__
    __sync_add_and_fetch( & m_count, 1 );
    #endif
}

#endif
