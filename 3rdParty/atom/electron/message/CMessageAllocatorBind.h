#ifndef CMESSAGEALLOCATORBIND_H
#define CMESSAGEALLOCATORBIND_H
#include "../Common.h"
#include "CMessage.h"



namespace electron
{
    


    typedef CAllocator<CMessage,128,16> CMessageAllocatorBind;



} //end namespace electron



#endif
