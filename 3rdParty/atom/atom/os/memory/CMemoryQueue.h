#ifndef CMEMORYQUEUE_H
#define CMEMORYQUEUE_H
#include "CMemoryQueueBind.h"
#include "tagMemorySector.h"
#include "../thread/CCriticalSection.h"



namespace atom
{



     class CMemoryQueue
     {


         private:


             size_t limit;



             CMemoryQueueBind queue;



             CCriticalSection section;




         public:

             inline CMemoryQueue(); 



             inline ~CMemoryQueue(); 



             inline bool Put(tagMemorySector * pointer); 



             inline tagMemorySector * Get(); 



             inline void GetAll(CMemoryQueueBind & out); 



             inline void SetLimit(size_t value); 



     };  //end class CMemoryQueue


}//end namespace atom


atom::CMemoryQueue::CMemoryQueue() : 
limit(0)
{
}

atom::CMemoryQueue::~CMemoryQueue() 
{
}

bool atom::CMemoryQueue::Put(tagMemorySector * pointer) 
{
    if( !pointer ) return false;

    bool result( false );
    section.Enter();
    if( queue.size() < limit ) {
        queue.push_back( pointer ); result = true;
    }
    section.Leave();
    return result;
}

atom::tagMemorySector * atom::CMemoryQueue::Get() 
{
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

void atom::CMemoryQueue::GetAll(CMemoryQueueBind & out) 
{
    section.Enter();
    std::copy( queue.begin(), queue.end(), back_inserter(out) ); 
    queue.clear();
    section.Leave();
}

void atom::CMemoryQueue::SetLimit(size_t value) 
{
    section.Enter();
    limit = value; queue.reserve( limit );
    section.Leave();
}

#endif
