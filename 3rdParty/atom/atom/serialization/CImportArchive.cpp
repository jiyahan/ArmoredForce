#include "CImportArchive.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IImportable.h"
#include "../enumeration/INTERFACE_ID.h"
//Begin section for file CImportArchive.cpp
//TODO: Add definitions that you want preserved
//End section for file CImportArchive.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImportArchive::CImportArchive() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImportArchive::~CImportArchive() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CImportArchive::IncRef() 
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
int atom::CImportArchive::DecRef() 
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
int atom::CImportArchive::GetRef() 
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
atom::IInterface * atom::CImportArchive::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::SetNest(IInterface * value) 
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
void atom::CImportArchive::Bind(bool & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU08() > 0;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(char & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU08();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(I08 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI08();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(I16 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI16();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(I32 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI32();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(I64 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI64();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(U08 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU08();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(U16 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU16();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(U32 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU32();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(U64 & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU64();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(float & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadFloat();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(double & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadDouble();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(a_string & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) 
    {
        U08 flags;
        flags = segment -> ReadU08();

        flags ?
        value = segment -> ReadUtf8String():
        value = segment -> ReadString();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(a_wstring & value) 
{
    //TODO Auto-generated method stub
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        segment -> ReadU08();
        value = segment -> ReadWString();
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportArchive::Bind(void * buffer, U64 length) 
{
    //TODO Auto-generated method stub
    if( buffer && length )
    {
        CInterface<IImportable> segment;
        if( segment.Mount(this, IID_IMPORTABLE) ) {
            segment -> ReadBytes( buffer, length );
        }
    }
}
