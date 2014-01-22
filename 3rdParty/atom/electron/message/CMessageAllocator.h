#ifndef CMESSAGEALLOCATOR_H
#define CMESSAGEALLOCATOR_H
#include "CMessageAllocatorSingletonBind.h"
#include "CMessageAllocatorBind.h"



namespace electron
{



    class CMessageAllocator : public CMessageAllocatorSingletonBind, public CMessageAllocatorBind
    {


        public:



            inline void  Released(CMessage * object)
            {
                if( object )
                {
                    object -> Shutdown();
                    CMessageAllocatorBind::Released( object );
                }
            }



    };  //end class CMessageAllocator



} //end namespace electron



#endif
