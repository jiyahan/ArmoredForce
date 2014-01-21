#pragma once

#include "atom/CAtom.h"
#include "ClientEventHandleReceiver.h"


class ClientEventHandle : public CReferencedObject
{
private:
    ClientEventHandleReceiver receiver;

public:

    ClientEventHandle(); 

    virtual ~ClientEventHandle(); 


    const char * ToString(); 

    IInterface * QueryInterface(U32 iid); 

}; 

