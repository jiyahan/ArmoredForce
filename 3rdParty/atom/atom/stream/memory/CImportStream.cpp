#include "CImportStream.h"
#include "../../utility/tool/CCriticalSectionScope.h"


atom::CImportStream::CImportStream() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
site(0),wide(0)
{
}

atom::CImportStream::~CImportStream() 
{
    Close();
}

int atom::CImportStream::IncRef() 
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

int atom::CImportStream::DecRef() 
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

int atom::CImportStream::GetRef() 
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

atom::IInterface * atom::CImportStream::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CImportStream::SetNest(IInterface * value) 
{
    if( value ) 
	{
		nest = value;
		#ifdef _SHIPPING_
		cast = dynamic_cast<IReferencedInterface *>( nest );
		#endif
	}
}

char atom::CImportStream::Read() 
{
    char result = 0;
    Read( & result, sizeof(char) );
    return result;
}

U64 atom::CImportStream::Read(void * buffer, U64 counts) 
{
    U64 copied = 0;
    if( buffer && counts )
    {
        CCriticalSectionScope scope( clog );
        if( site + counts <= wide )
        {
            // 定义流内的每个块的头部位移
            U64 offset = 0;
            for( CImportStreamBind::iterator 
                it = data.begin(); it != data.end(); ++ it )
            {
                // 首先判断这个块是否有效。
                if( it -> GetLength() == 0  ) continue;

                // 如果块有效，继续判断这个块是否有需要的数据。一个块内包含有效数据的判断依据：
                // site属于[offfset，offset + data[i].length]这个区间。
                U64 remain(0), needed(0);
                if( offset + it -> GetLength() > site )
                {
                    // 如果起始位置在这个块内。计算起始位置：
                    U64 inner = 0;
                    if( site > offset ) inner = site - offset;

                    // 计算这个块内的剩余字节。
                    remain = it -> GetLength() - inner;

                    // 剩余字节数加拷贝了的字节数是否大于缓冲区长度？获取这个缓冲区内实际需要拷贝的字节数。
                    remain + copied <= counts ? needed = remain : needed = counts - copied;

                    // 开始拷贝数据，但是不要拨动碎片内的位移参数。
                    memcpy( reinterpret_cast<char*>(buffer) + copied, 
                        it -> Query<char>() + inner, static_cast<size_t>(needed) );
                    copied += needed;
                }

                // 增加块头部的位移。
                offset += it -> GetLength();

                // 如果读取完成，则跳出循环。
                if( copied >= counts ) break;
            }
        }

        // 读取结束，拨动位移。
        counts == copied ? site += copied : copied = 0;
    }

    // Debug Code
    //printf( "Read %llu Bytes, Try To Read %llu Bytes\n", copied, counts );
    //for( U64 i = 0; i < copied; i ++ ) {
    //    printf( "%.2X ", ((char*)buffer)[i] );
    //}
    //printf( "\n" );

    return copied;
}

U64 atom::CImportStream::Read(void * value, U64 offset, U64 length) 
{
    return Read( reinterpret_cast<char*>(value) + offset, length );
}

void atom::CImportStream::Close() 
{
    Reset();
}

U64 atom::CImportStream::Available() 
{
    U64 result = 0;
    CCriticalSectionScope scope( clog );
    if( site < wide ) result = wide - site;
    return result;
}

void atom::CImportStream::Mark(U64 offset) 
{
    CCriticalSectionScope scope( clog );
    site = atom_min( wide, offset );
}

void atom::CImportStream::Reset() 
{
    CCriticalSectionScope scope( clog );
    site = 0;
    wide = 0;
    data.clear();
}

I64 atom::CImportStream::Skip(I64 bytes) 
{
    CCriticalSectionScope scope( clog );
    I64 offset = static_cast<I64>( site ) + bytes;

    offset = atom_max( offset, 0 );
    offset = atom_min( offset, static_cast<I64>(wide) );

    I64 okey = offset - static_cast<I64>( site );
    site = static_cast<U64>( offset ); 
    return okey;
}

void atom::CImportStream::Truncate() 
{
    CCriticalSectionScope scope( clog );
    if( wide && site )
    {
        // 定义临时位移
        U64 offset = 0;
        CImportStreamBind::iterator it = data.begin();
        for( ; it != data.end(); )
        {
            // 判断这个块是否可以移出。如果不能移出，则终止循环。
            if( offset + it -> GetLength() > site ) {
                break;
            }

            // 增加临时位移；
            offset += it -> GetLength();

            // 删除该内存块；
            it = data.erase( it );
        }

        // 循环终止后，减少流的长度和位移
        if( offset )
        {
            site -= offset;
            wide -= offset;
        }
    }
}

bool atom::CImportStream::Assign(CMemory & value) 
{
    bool result = false;
    result = value.GetLength() > 0;
    if( result )
    {
        clog.Enter();
        data.push_back( value ); wide += value.GetLength();
        clog.Leave();
    }
    return result;
}

bool atom::CImportStream::Swap(CMemory & out) 
{
    bool result = false;
    CCriticalSectionScope scope( clog );
        
    CMemory swap;
    result = swap.Alloc( static_cast<size_t>(wide) );
    if( result )
    {
        // 首先分配内存，将data内的数据拷贝出来；
        U64 offset = 0;
        for( CImportStreamBind::iterator 
            it = data.begin(); it != data.end(); ++ it )
        {
            memcpy( swap.Query<char>() + offset, it -> Query<char>(), it -> GetLength() );
            offset += it -> GetLength();
        }
        swap.SetLength( static_cast<size_t>(wide) );
            
        // 当拷贝完成之后，重置data相关的数据；
        site = 0;
        wide = out.GetLength();

        data.clear();
        if( out.GetLength() ) data.push_back( out );                
            
        // 将swap赋予block；
        out = swap;
    }
    return result;
}
