#include "CStream.h"
#include "../../interface/IFlushDevice.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"
//Begin section for file CStream.cpp
//TODO: Add definitions that you want preserved
//End section for file CStream.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CStream::CStream() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
site(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CStream::~CStream() 
{
    //TODO Auto-generated method stub
    Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CStream::Resize(size_t size) 
{
    //TODO Auto-generated method stub
    size_t increase = static_cast<size_t>( ( data.GetCapacity() + size ) * 0.5 );
    increase = atom_max( increase, DEFAULT_MEMORY_SIZE );
    increase = atom_min( increase, 16777216 );

    CMemory buffer;
    size_t capacity = data.GetCapacity() + size + increase;

    // 分配空间，然后拷贝原有的数据到新的空间。
    bool result = false;
    if( buffer.Alloc(capacity) )
    {
        // 拷贝数据。
        result = buffer.Store( data, data.GetLength() );

        // 用新的缓冲区替代旧的缓冲区。
        data = buffer;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CStream::CheckCapacity(size_t size) 
{
    //TODO Auto-generated method stub
    bool result = false;
    data.GetCapacity() >= data.GetLength() + size ? result = true : result = Resize( size );
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CStream::IncRef() 
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
int atom::CStream::DecRef() 
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
int atom::CStream::GetRef() 
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
atom::IInterface * atom::CStream::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::SetNest(IInterface * value) 
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
char atom::CStream::Read() 
{
    //TODO Auto-generated method stub
    char result = 0;
    Read( & result, sizeof(char) );
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CStream::Read(void * buffer, U64 length) 
{
    //TODO Auto-generated method stub
    U64 copy = 0;
    if( buffer && length )
    {
        CCriticalSectionScope scope( clog );
        if( site + length <= data.GetLength() )
        {
            memcpy( buffer, data.Query<char>() + site, static_cast<size_t>(length) );
            site += length;
            copy  = length;
        }
    }
    return copy;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CStream::Read(void * value, U64 offset, U64 length) 
{
    //TODO Auto-generated method stub
    return Read( reinterpret_cast<char*>(value) + offset, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Write(char value) 
{
    //TODO Auto-generated method stub
    Write( & value, sizeof(char) );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Write(const void * buffer, U64 length) 
{
    //TODO Auto-generated method stub
    if( buffer && length )
    {
        // 进入临界区，开始准备数据。
        CCriticalSectionScope scope( clog );
        if( CheckCapacity( static_cast<size_t>(length) ) )
        {
            // 如果CheckCapacity成功，那么，data内必定有足够的空间来容纳数据。
            memcpy( data.Query<char>() + data.GetLength(), buffer, static_cast<size_t>(length) );
            data.SetLength( static_cast<size_t>( data.GetLength() + length ) );
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Write(const void * value, U64 offset, U64 length) 
{
    //TODO Auto-generated method stub
    Write( reinterpret_cast<const char*>(value) + offset, static_cast<size_t>(length) );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Close() 
{
    //TODO Auto-generated method stub
    Reset();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Truncate() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    if( site )
    {
        CMemory swap;
        if( swap.Alloc( data.GetCapacity() ) )
        {
            // 拷贝数据，并设置缓冲区内数据的长度。
            if( data.GetLength() > site ) {
                swap.Store( data.Query<char>() + site, static_cast<size_t>( data.GetLength() - site ) );
            }

            // 用新的缓冲区替换原有的缓冲区。
            data = swap; site = 0;
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Flush() 
{
    //TODO Auto-generated method stub
    CInterface<IFlushDevice> segment;
    if( segment.Mount(this, IID_FLUSH_DEVICE) )
    {
        CCriticalSectionScope scope( clog );    
        if( segment -> OnFlush(data) ) {
            site = 0; data.Clear(); 
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CStream::Available() 
{
    //TODO Auto-generated method stub
    U64 result = 0;
    CCriticalSectionScope scope( clog );
    if( site < data.GetLength() ) {
        result = data.GetLength() - site;
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CStream::Length() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    return data.GetLength();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Mark(U64 offset) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    site = atom_min( data.GetLength(), offset );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CStream::Reset() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    data.Clear(); site = 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I64 atom::CStream::Skip(I64 bytes) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    I64 offset = static_cast<I64>( site ) + bytes;

    offset = atom_max( offset, 0 );
    offset = atom_min( offset, static_cast<I64>( data.GetLength() ) );

    I64 okey = offset - static_cast<I64>( site );
    site = static_cast<U64>( offset ); 
    return okey;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CStream::Assign(CMemory & value) 
{
    //TODO Auto-generated method stub
    Write( value, value.GetLength() );
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CStream::Swap(CMemory & node) 
{
    //TODO Auto-generated method stub
    CMemory swap;
    CCriticalSectionScope scope( clog );

    swap = data;
    data = node;
    node = swap;
    site = 0;

    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CStream::Clone(CMemory & out) 
{
    //TODO Auto-generated method stub
    bool result = false;
    CCriticalSectionScope scope( clog );
    if( out.Alloc( data.GetLength() ) ) {
        result = out.Store( data, data.GetLength() );
    }
    return result;
}
