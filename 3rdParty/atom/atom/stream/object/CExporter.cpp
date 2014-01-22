#include "CExporter.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CExporter::CExporter() 
{
    stream.SetNest( this );
}

atom::CExporter::~CExporter() 
{
    stream.Close();
}

atom::IInterface * atom::CExporter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_EXPORT_STREAM:
        result = & stream;
        break;
    }
    return result;
}
