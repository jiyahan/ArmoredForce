#include "CExportStream.h"
#include "../../interface/IFlushDevice.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/tool/CInterface.h"


atom::CExportStream::CExportStream() : 
nest(NULL)
#ifdef _SHIPPING_
,cast(NULL)
#endif
{
}

atom::CExportStream::~CExportStream() 
{
    Close();
}

bool atom::CExportStream::Resize(size_t size) 
{
    size_t increase = static_cast<size_t>( ( data.GetCapacity() + size ) * 0.5f );
    increase = atom_max( increase, DEFAULT_MEMORY_SIZE );
    increase = atom_min( increase, 16777216 );

    CMemory buffer;
    size_t capacity = data.GetCapacity() + size + increase;

    // 分配空间，然后拷贝原有的数据到新的空间。
    bool result(false);
    if( buffer.Alloc(capacity) )
    {
        // 如果新缓冲区以及原有的缓冲区的指针有效，那么拷贝数据，并设置长度。
        result = buffer.Store( data, data.GetLength() );

        // 用新的缓冲区替代旧的缓冲区。
        data = buffer;
    }
    return result;
}

bool atom::CExportStream::CheckCapacity(size_t size) 
{
    // 存在一个已知的Buffer，那么检查这个Buffer的空间是否足够。
    bool result = false;
    data.GetCapacity() >= data.GetLength() + size ? result = true : result = Resize( size );
    return result;
}

int atom::CExportStream::IncRef() 
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

int atom::CExportStream::DecRef() 
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

int atom::CExportStream::GetRef() 
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

atom::IInterface * atom::CExportStream::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CExportStream::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

void atom::CExportStream::Write(char value) 
{
    Write( & value, sizeof(char) );
}

void atom::CExportStream::Write(const void * buffer, U64 length) 
{
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

void atom::CExportStream::Write(const void * value, U64 offset, U64 length) 
{
    Write( reinterpret_cast<const char*>(value) + offset, static_cast<size_t>(length) );
}

void atom::CExportStream::Close() 
{
    CCriticalSectionScope scope( clog );
    data.Clear();
}

void atom::CExportStream::Flush() 
{
    CInterface<IFlushDevice> segment;
    if( segment.Mount(this, IID_FLUSH_DEVICE) )
    {
        CCriticalSectionScope scope( clog );    
        if( segment -> OnFlush(data) ) {
            data.Clear();
        }
    }
}

U64 atom::CExportStream::Length() 
{
    CCriticalSectionScope scope( clog );
    return data.GetLength();
}

bool atom::CExportStream::Clone(CMemory & out) 
{
    CCriticalSectionScope scope( clog );

    bool result(false);
    if( out.Alloc( data.GetLength() ) ) {
        result = out.Store( data, data.GetLength() );
    }
    return result;
}

bool atom::CExportStream::Swap(CMemory & node) 
{
    CMemory swap;
    CCriticalSectionScope scope( clog );
    swap = data; data = node; node = swap;
    return true;
}
