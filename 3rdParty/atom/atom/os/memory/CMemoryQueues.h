#ifndef CMEMORYQUEUES_H
#define CMEMORYQUEUES_H
//Begin section for file CMemoryQueues.h
//TODO: Add definitions that you want preserved
//End section for file CMemoryQueues.h
#include "CMemoryQueue.h"
#include "CMemoryQueueBind.h"
#include "tagMemorySector.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMemoryQueues
    {

        //Begin section for atom::CMemoryQueues
        //TODO: Add attributes that you want preserved
        //End section for atom::CMemoryQueues

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMemoryQueue queues[MEMORY_FRAGMENT_QUEUE];




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMemoryQueues(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CMemoryQueues(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Put(size_t level, tagMemorySector * pointer); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagMemorySector * Get(size_t level); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void GetAll(CMemoryQueueBind & out); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void SetLimit(size_t level, size_t value); 



    };  //end class CMemoryQueues


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemoryQueues::CMemoryQueues() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemoryQueues::~CMemoryQueues() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemoryQueues::Put(size_t level, tagMemorySector * pointer) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( pointer && level < MEMORY_FRAGMENT_QUEUE ) {
        result = queues[level].Put( pointer );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemorySector * atom::CMemoryQueues::Get(size_t level) 
{
    //TODO Auto-generated method stub
    tagMemorySector * result = NULL;
    if( level < MEMORY_FRAGMENT_QUEUE ) {
        result = queues[level].Get();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryQueues::GetAll(CMemoryQueueBind & out) 
{
    //TODO Auto-generated method stub
    for( size_t i = 0; i < MEMORY_FRAGMENT_QUEUE; ++ i ) {
        queues[i].GetAll( out );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryQueues::SetLimit(size_t level, size_t value) 
{
    //TODO Auto-generated method stub
    if( level < MEMORY_FRAGMENT_QUEUE ) {
        queues[level].SetLimit( value );
    }
}

#endif
