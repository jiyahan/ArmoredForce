#ifndef CMEMORYQUEUES_H
#define CMEMORYQUEUES_H
#include "CMemoryQueue.h"
#include "CMemoryQueueBind.h"
#include "tagMemorySector.h"



namespace atom
{



    class CMemoryQueues
    {


        private:


            CMemoryQueue queues[MEMORY_FRAGMENT_QUEUE];




        public:

            inline CMemoryQueues(); 



            inline ~CMemoryQueues(); 



            inline bool Put(size_t level, tagMemorySector * pointer); 



            inline tagMemorySector * Get(size_t level); 



            inline void GetAll(CMemoryQueueBind & out); 



            inline void SetLimit(size_t level, size_t value); 



    };  //end class CMemoryQueues


}//end namespace atom


atom::CMemoryQueues::CMemoryQueues() 
{
}

atom::CMemoryQueues::~CMemoryQueues() 
{
}

bool atom::CMemoryQueues::Put(size_t level, tagMemorySector * pointer) 
{
    bool result = false;
    if( pointer && level < MEMORY_FRAGMENT_QUEUE ) {
        result = queues[level].Put( pointer );
    }
    return result;
}

atom::tagMemorySector * atom::CMemoryQueues::Get(size_t level) 
{
    tagMemorySector * result = NULL;
    if( level < MEMORY_FRAGMENT_QUEUE ) {
        result = queues[level].Get();
    }
    return result;
}

void atom::CMemoryQueues::GetAll(CMemoryQueueBind & out) 
{
    for( size_t i = 0; i < MEMORY_FRAGMENT_QUEUE; ++ i ) {
        queues[i].GetAll( out );
    }
}

void atom::CMemoryQueues::SetLimit(size_t level, size_t value) 
{
    if( level < MEMORY_FRAGMENT_QUEUE ) {
        queues[level].SetLimit( value );
    }
}

#endif
