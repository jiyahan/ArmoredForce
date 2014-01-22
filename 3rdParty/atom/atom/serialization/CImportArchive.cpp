#include "CImportArchive.h"
#include "../utility/tool/CInterface.h"
#include "../interface/IImportable.h"
#include "../enumeration/INTERFACE_ID.h"


atom::CImportArchive::CImportArchive() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CImportArchive::~CImportArchive() 
{
}

int atom::CImportArchive::IncRef() 
{
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

int atom::CImportArchive::DecRef() 
{
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

int atom::CImportArchive::GetRef() 
{
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

atom::IInterface * atom::CImportArchive::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CImportArchive::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void atom::CImportArchive::Bind(bool & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU08() > 0;
    }
}

void atom::CImportArchive::Bind(char & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU08();
    }
}

void atom::CImportArchive::Bind(I08 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI08();
    }
}

void atom::CImportArchive::Bind(I16 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI16();
    }
}

void atom::CImportArchive::Bind(I32 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI32();
    }
}

void atom::CImportArchive::Bind(I64 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadI64();
    }
}

void atom::CImportArchive::Bind(U08 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU08();
    }
}

void atom::CImportArchive::Bind(U16 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU16();
    }
}

void atom::CImportArchive::Bind(U32 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU32();
    }
}

void atom::CImportArchive::Bind(U64 & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadU64();
    }
}

void atom::CImportArchive::Bind(float & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadFloat();
    }
}

void atom::CImportArchive::Bind(double & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        value = segment -> ReadDouble();
    }
}

void atom::CImportArchive::Bind(a_string & value) 
{
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

void atom::CImportArchive::Bind(a_wstring & value) 
{
    CInterface<IImportable> segment;
    if( segment.Mount(this, IID_IMPORTABLE) ) {
        segment -> ReadU08();
        value = segment -> ReadWString();
    }
}

void atom::CImportArchive::Bind(void * buffer, U64 length) 
{
    if( buffer && length )
    {
        CInterface<IImportable> segment;
        if( segment.Mount(this, IID_IMPORTABLE) ) {
            segment -> ReadBytes( buffer, length );
        }
    }
}
