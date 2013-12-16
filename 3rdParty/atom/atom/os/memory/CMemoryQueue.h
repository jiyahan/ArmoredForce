#ifndef CMEMORYQUEUE_H
#define CMEMORYQUEUE_H
//Begin section for file CMemoryQueue.h
//TODO: Add definitions that you want preserved
//End section for file CMemoryQueue.h
#include "CMemoryQueueBind.h"
#include "tagMemorySector.h"
#include "../thread/CCriticalSection.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class CMemoryQueue
     {

         //Begin section for atom::CMemoryQueue
         //TODO: Add attributes that you want preserved
         //End section for atom::CMemoryQueue

         private:


             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             size_t limit;



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             CMemoryQueueBind queue;



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             CCriticalSection section;




         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline CMemoryQueue(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline ~CMemoryQueue(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline bool Put(tagMemorySector * pointer); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline tagMemorySector * Get(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline void GetAll(CMemoryQueueBind & out); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline void SetLimit(size_t value); 



     };  //end class CMemoryQueue


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemoryQueue::CMemoryQueue() : 
limit(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CMemoryQueue::~CMemoryQueue() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CMemoryQueue::Put(tagMemorySector * pointer) 
{
    //TODO Auto-generated method stub
    if( !pointer ) return false;

    bool result( false );
    section.Enter();
    if( queue.size() < limit ) {
        queue.push_back( pointer ); result = true;
    }
    section.Leave();
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemorySector * atom::CMemoryQueue::Get() 
{
    //TODO Auto-generated method stub
    tagMemorySector* result = NULL;
    {
        section.Enter();
        if( !queue.empty() ) {
            result = queue.back();
            queue.pop_back();
        }
        section.Leave();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryQueue::GetAll(CMemoryQueueBind & out) 
{
    //TODO Auto-generated method stub
    section.Enter();
    std::copy( queue.begin(), queue.end(), back_inserter(out) ); 
    queue.clear();
    section.Leave();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CMemoryQueue::SetLimit(size_t value) 
{
    //TODO Auto-generated method stub
    section.Enter();
    limit = value; queue.reserve( limit );
    section.Leave();
}

#endif
