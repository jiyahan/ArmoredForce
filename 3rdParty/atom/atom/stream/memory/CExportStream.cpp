#include "CExportStream.h"
#include "../../interface/IFlushDevice.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CExportStream.cpp
//TODO: Add definitions that you want preserved
//End section for file CExportStream.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CExportStream::CExportStream() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CExportStream::~CExportStream() 
{
    //TODO Auto-generated method stub
    Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CExportStream::Resize(size_t size) 
{
    //TODO Auto-generated method stub
    size_t increase = static_cast<size_t>( ( data.GetCapacity() + size ) * 0.5f );
    increase = atom_max( increase, DEFAULT_MEMORY_SIZE );
    increase = atom_min( increase, 16777216 );

    CMemory buffer;
    size_t capacity = data.GetCapacity() + size + increase;

    // ����ռ䣬Ȼ�󿽱�ԭ�е����ݵ��µĿռ䡣
    bool result(false);
    if( buffer.Alloc(capacity) )
    {
        // ����»������Լ�ԭ�еĻ�������ָ����Ч����ô�������ݣ������ó��ȡ�
        result = buffer.Store( data, data.GetLength() );

        // ���µĻ���������ɵĻ�������
        data = buffer;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CExportStream::CheckCapacity(size_t size) 
{
    //TODO Auto-generated method stub
    // ����һ����֪��Buffer����ô������Buffer�Ŀռ��Ƿ��㹻��
    bool result = false;
    data.GetCapacity() >= data.GetLength() + size ? result = true : result = Resize( size );
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CExportStream::IncRef() 
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
int atom::CExportStream::DecRef() 
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
int atom::CExportStream::GetRef() 
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
atom::IInterface * atom::CExportStream::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportStream::SetNest(IInterface * value) 
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
void atom::CExportStream::Write(char value) 
{
    //TODO Auto-generated method stub
    Write( & value, sizeof(char) );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportStream::Write(const void * buffer, U64 length) 
{
    //TODO Auto-generated method stub
    if( buffer && length )
    {
        // �����ٽ�������ʼ׼�����ݡ�
        CCriticalSectionScope scope( clog );
        if( CheckCapacity( static_cast<size_t>(length) ) )
        {
            // ���CheckCapacity�ɹ�����ô��data�ڱض����㹻�Ŀռ����������ݡ�
            memcpy( data.Query<char>() + data.GetLength(), buffer, static_cast<size_t>(length) );
            data.SetLength( static_cast<size_t>( data.GetLength() + length ) );
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportStream::Write(const void * value, U64 offset, U64 length) 
{
    //TODO Auto-generated method stub
    Write( reinterpret_cast<const char*>(value) + offset, static_cast<size_t>(length) );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportStream::Close() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    data.Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CExportStream::Flush() 
{
    //TODO Auto-generated method stub
    CInterface<IFlushDevice> segment;
    if( segment.Mount(this, IID_FLUSH_DEVICE) )
    {
        CCriticalSectionScope scope( clog );    
        if( segment -> OnFlush(data) ) {
            data.Clear();
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CExportStream::Length() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    return data.GetLength();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CExportStream::Clone(CMemory & out) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );

    bool result(false);
    if( out.Alloc( data.GetLength() ) ) {
        result = out.Store( data, data.GetLength() );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CExportStream::Swap(CMemory & node) 
{
    //TODO Auto-generated method stub
    CMemory swap;
    CCriticalSectionScope scope( clog );
    swap = data; data = node; node = swap;
    return true;
}
