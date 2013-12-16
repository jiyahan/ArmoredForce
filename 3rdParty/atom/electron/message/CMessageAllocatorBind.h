#ifndef CMESSAGEALLOCATORBIND_H
#define CMESSAGEALLOCATORBIND_H
//Begin section for file CMessageAllocatorBind.h
//TODO: Add definitions that you want preserved
//End section for file CMessageAllocatorBind.h
#include "../Common.h"
#include "CMessage.h"



namespace electron
{
    


    typedef CAllocator<CMessage,128,16> CMessageAllocatorBind;



} //end namespace electron



#endif
