#include "CImporter.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CImporter.cpp
//TODO: Add definitions that you want preserved
//End section for file CImporter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImporter::CImporter() 
{
    //TODO Auto-generated method stub
    stream.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImporter::~CImporter() 
{
    //TODO Auto-generated method stub
    stream.Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CImporter::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_IMPORT_STREAM:
        result = & stream;
        break;
    }
    return result;
}
