#pragma once

#include <atom/CAtom.h>
#include "CClientEventHandleReceiver.h"


class CClientEventHandle : public CReferencedObject
{
public:
    CClientEventHandle(); 
    virtual ~CClientEventHandle(); 


    const char*     ToString(); 
    IInterface*     QueryInterface(U32 iid); 

private:
    CClientEventHandleReceiver receiver_;
}; 

