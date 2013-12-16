#include "CExporter.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CExporter.cpp
//TODO: Add definitions that you want preserved
//End section for file CExporter.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CExporter::CExporter() 
{
    //TODO Auto-generated method stub
    stream.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CExporter::~CExporter() 
{
    //TODO Auto-generated method stub
    stream.Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CExporter::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_EXPORT_STREAM:
        result = & stream;
        break;
    }
    return result;
}
