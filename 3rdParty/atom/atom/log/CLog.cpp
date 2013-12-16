#include "CLog.h"
#include "../enumeration/INTERFACE_ID.h"
#include "../enumeration/LOG_LEVEL.h"
//Begin section for file CLog.cpp
//TODO: Add definitions that you want preserved
//End section for file CLog.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLog::CLog() 
{
    //TODO Auto-generated method stub
    archive .SetNest( this );
    exporter.SetNest( this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLog::~CLog() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CLog::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    switch( iid )
    {
    case IID_LOG_ARCHIVE:
        result = & archive;
        break;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLog & atom::CLog::operator <<(const char * message) 
{
    //TODO Auto-generated method stub
    archive.Append( message );
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CLog & atom::CLog::operator <<(LINE_END flag) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( flag );
    archive.Append( "\r\n" );
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLog::operator <<(END_DEBUG flag) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( flag );
    archive.Finish( LL_DEBUG );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLog::operator <<(END_ALARM flag) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( flag );
    archive.Finish( LL_ALARM );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CLog::operator <<(END_ERROR flag) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( flag );
    archive.Finish( LL_ERROR );
}
