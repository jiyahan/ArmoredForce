#pragma once

#include "atom/CAtom.h"
#include "CClientEventHandleReceiver.h"


class CClientEventHandle : public CReferencedObject
{
private:
    CClientEventHandleReceiver receiver;

public:

    CClientEventHandle(); 

    virtual ~CClientEventHandle(); 


    const char * ToString(); 

    IInterface * QueryInterface(U32 iid); 

}; 

