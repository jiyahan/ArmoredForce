#include "CExportArchive.h"
#include "../utility/charset/CUtf8Charset.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IExportable.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CExportArchive.cpp
//TODO: Add definitions that you want preserved
//End section for file CExportArchive.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CExportArchive::CExportArchive() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CExportArchive::~CExportArchive() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CExportArchive::IncRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> IncRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CExportArchive::DecRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> DecRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CExportArchive::GetRef() 
{
    //TODO Auto-generated method stub
    int result = 0;
	#ifdef _SHIPPING_
	if( cast )
	{
		result = cast -> GetRef();
	}
	#else
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
	#endif
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IInterface * atom::CExportArchive::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::SetNest(IInterface * value) 
{
    //TODO Auto-generated method stub
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(bool & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( static_cast<U08>(value) );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(char & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( static_cast<U08>(value) );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(I08 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(I16 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(I32 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(I64 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(U08 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(U16 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(U32 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(U64 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(float & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(double & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( value );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(a_string & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) 
    {
        U08 flags = CUtf8Charset::IsUtf8( value.c_str() );
        segment -> Write( flags );
        segment -> Write( value.c_str() );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(a_wstring & value) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( U08(true) );
        segment -> Write( value.c_str() );
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportArchive::Bind(void * buffer, U64 length) 
{
    //TODO Auto-generated method stub
    CInterface<IExportable> segment;
    if( segment.Mount(this, IID_EXPORTABLE) ) {
        segment -> Write( buffer, length );
    }
}
