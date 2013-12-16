#include "CClosableWrapper.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "../../enumeration/INTERFACE_ID.h"
//Begin section for file CClosableWrapper.cpp
//TODO: Add definitions that you want preserved
//End section for file CClosableWrapper.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CClosableWrapper::CClosableWrapper() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
bind(NULL),size(0)
{
    //TODO Auto-generated method stub
    wrap[0] = IID_UNKNOW;
    wrap[1] = IID_UNKNOW;
    wrap[2] = IID_UNKNOW;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CClosableWrapper::~CClosableWrapper() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CClosableWrapper::Verify() 
{
    //TODO Auto-generated method stub
    if( bind )
    {
        IInterface * unknow;
        unknow = bind -> QueryInterface( IID_IMPORT_STREAM );
        if( unknow )
        {
            wrap[size ++] = IID_IMPORT_STREAM;
            IReferencedInterface * refered = 
                dynamic_cast<IReferencedInterface *>( unknow );
            SAFE_DECREF( refered );
        }

        unknow = bind -> QueryInterface( IID_EXPORT_STREAM );
        if( unknow )
        {
            wrap[size ++] = IID_EXPORT_STREAM;
            IReferencedInterface * refered = 
                dynamic_cast<IReferencedInterface *>( unknow );
            SAFE_DECREF( refered );
        }

        unknow = bind -> QueryInterface( IID_STREAM );
        if( unknow )
        {
            wrap[size ++] = IID_STREAM;
            IReferencedInterface * refered = 
                dynamic_cast<IReferencedInterface *>( unknow );
            SAFE_DECREF( refered );
        }        
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CClosableWrapper::Attach(IInterface * value) 
{
    //TODO Auto-generated method stub
    /* not increase any reference, nest will do it */
    bind = value;
    wrap[0] = IID_UNKNOW;
    wrap[1] = IID_UNKNOW;
    wrap[2] = IID_UNKNOW;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CClosableWrapper::IncRef() 
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
int atom::CClosableWrapper::DecRef() 
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
int atom::CClosableWrapper::GetRef() 
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
atom::IInterface * atom::CClosableWrapper::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CClosableWrapper::SetNest(IInterface * value) 
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
void atom::CClosableWrapper::Close() 
{
    //TODO Auto-generated method stub
    if( !bind ) return;
    if( !size ) Verify();

    for( U08 i = 0; i < size; ++ i )
    {
        IInterface * unknow = bind -> QueryInterface( wrap[i] );
        if( unknow )
        {
            switch( wrap[i] )
            {
            case IID_IMPORT_STREAM:
                {
                    IImportStream * stream = 
                        dynamic_cast<IImportStream *>( unknow );
                    if( stream ) {
                        stream -> Close();
                    }
                }
                break;
            case IID_EXPORT_STREAM:
                {
                    IExportStream * stream = 
                        dynamic_cast<IExportStream *>( unknow );
                    if( stream ) {
                        stream -> Close();
                    }
                }
                break;
            case IID_STREAM:
                {
                    IStream * stream = dynamic_cast<IStream *>( unknow );
                    if( stream ) {
                        stream -> Close();
                    }
                }
                break;
            }

            IReferencedInterface * refered = 
                dynamic_cast<IReferencedInterface *>( unknow );
            SAFE_DECREF( refered );
        }
    }
}
