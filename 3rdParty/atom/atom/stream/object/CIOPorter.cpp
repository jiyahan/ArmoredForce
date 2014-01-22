#include "CIOPorter.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CIOPorter::CIOPorter() 
{
    stream.SetNest( this );
}

atom::CIOPorter::~CIOPorter() 
{
    stream.Close();
}

atom::IInterface * atom::CIOPorter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_STREAM:
        result = & stream;
        break;
    }
    return result;
}
