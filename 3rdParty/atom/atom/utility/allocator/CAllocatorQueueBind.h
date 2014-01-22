#ifndef CALLOCATORQUEUEBIND_H
#define CALLOCATORQUEUEBIND_H
#include "../stl/allocator.h"



namespace atom
{



    template <class T>
    class CAllocatorQueueBind
    {


        public:


            typedef std::vector<T *, atom_allocator<T *> >  type ;




    };  //end class CAllocatorQueueBind



} //end namespace atom



#endif
