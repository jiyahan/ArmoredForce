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

bool atom::CExportStream::CheckCapacity(size_t size) 
{
    // ����һ����֪��Buffer����ô������Buffer�Ŀռ��Ƿ��㹻��
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
