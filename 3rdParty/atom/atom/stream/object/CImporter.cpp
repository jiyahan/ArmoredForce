#include "CImporter.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CImporter::CImporter() 
{
    stream.SetNest( this );
}

atom::CImporter::~CImporter() 
{
    stream.Close();
}

atom::IInterface * atom::CImporter::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_IMPORT_STREAM:
        result = & stream;
        break;
    }
    return result;
}
