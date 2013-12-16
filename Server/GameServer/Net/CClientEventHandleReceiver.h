#pragma once

#include "atom/CAtom.h"
#include "electron/CElectron.h"


class CClientEventHandleReceiver : public IEventReceiver
{
public:
    CClientEventHandleReceiver(); 
    virtual ~CClientEventHandleReceiver(); 

    virtual int IncRef(); 
    virtual int DecRef(); 
    virtual int GetRef(); 

    virtual IInterface * QueryInterface(U32 iid); 

    virtual void SetNest(IInterface * nest); 

    virtual bool OnEvent(const tagEvent & event); 

private:
    IInterface*    nest;
};


