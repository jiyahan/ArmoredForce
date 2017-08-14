#include "CImportStream.h"
#include "../../utility/tool/CCriticalSectionScope.h"
//Begin section for file CImportStream.cpp
//TODO: Add definitions that you want preserved
//End section for file CImportStream.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImportStream::CImportStream() : 
nest(NULL),
#ifdef _SHIPPING_
cast(NULL),
#endif
site(0),wide(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CImportStream::~CImportStream() 
{
    //TODO Auto-generated method stub
    Close();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CImportStream::IncRef() 
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
int atom::CImportStream::DecRef() 
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
int atom::CImportStream::GetRef() 
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
atom::IInterface * atom::CImportStream::QueryInterface(U32 iid) 
{
    //TODO Auto-generated method stub
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportStream::SetNest(IInterface * value) 
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
char atom::CImportStream::Read() 
{
    //TODO Auto-generated method stub
    char result = 0;
    Read( & result, sizeof(char) );
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CImportStream::Read(void * buffer, U64 counts) 
{
    //TODO Auto-generated method stub
    U64 copied = 0;
    if( buffer && counts )
    {
        CCriticalSectionScope scope( clog );
        if( site + counts <= wide )
        {
            // �������ڵ�ÿ�����ͷ��λ��
            U64 offset = 0;
            for( CImportStreamBind::iterator 
                it = data.begin(); it != data.end(); ++ it )
            {
                // �����ж�������Ƿ���Ч��
                if( it -> GetLength() == 0  ) continue;

                // �������Ч�������ж�������Ƿ�����Ҫ�����ݡ�һ�����ڰ�����Ч���ݵ��ж����ݣ�
                // site����[offfset��offset + data[i].length]������䡣
                U64 remain(0), needed(0);
                if( offset + it -> GetLength() > site )
                {
                    // �����ʼλ����������ڡ�������ʼλ�ã�
                    U64 inner = 0;
                    if( site > offset ) inner = site - offset;

                    // ����������ڵ�ʣ���ֽڡ�
                    remain = it -> GetLength() - inner;

                    // ʣ���ֽ����ӿ����˵��ֽ����Ƿ���ڻ��������ȣ���ȡ�����������ʵ����Ҫ�������ֽ�����
                    remain + copied <= counts ? needed = remain : needed = counts - copied;

                    // ��ʼ�������ݣ����ǲ�Ҫ������Ƭ�ڵ�λ�Ʋ�����
                    memcpy( reinterpret_cast<char*>(buffer) + copied, 
                        it -> Query<char>() + inner, static_cast<size_t>(needed) );
                    copied += needed;
                }

                // ���ӿ�ͷ����λ�ơ�
                offset += it -> GetLength();

                // �����ȡ��ɣ�������ѭ����
                if( copied >= counts ) break;
            }
        }

        // ��ȡ����������λ�ơ�
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CImportStream::Read(void * value, U64 offset, U64 length) 
{
    //TODO Auto-generated method stub
    return Read( reinterpret_cast<char*>(value) + offset, length );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportStream::Close() 
{
    //TODO Auto-generated method stub
    Reset();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CImportStream::Available() 
{
    //TODO Auto-generated method stub
    U64 result = 0;
    CCriticalSectionScope scope( clog );
    if( site < wide ) result = wide - site;
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportStream::Mark(U64 offset) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    site = atom_min( wide, offset );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportStream::Reset() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    site = 0;
    wide = 0;
    data.clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I64 atom::CImportStream::Skip(I64 bytes) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    I64 offset = static_cast<I64>( site ) + bytes;

    offset = atom_max( offset, 0 );
    offset = atom_min( offset, static_cast<I64>(wide) );

    I64 okey = offset - static_cast<I64>( site );
    site = static_cast<U64>( offset ); 
    return okey;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CImportStream::Truncate() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    if( wide && site )
    {
        // ������ʱλ��
        U64 offset = 0;
        CImportStreamBind::iterator it = data.begin();
        for( ; it != data.end(); )
        {
            // �ж�������Ƿ�����Ƴ�����������Ƴ�������ֹѭ����
            if( offset + it -> GetLength() > site ) {
                break;
            }

            // ������ʱλ�ƣ�
            offset += it -> GetLength();

            // ɾ�����ڴ�飻
            it = data.erase( it );
        }

        // ѭ����ֹ�󣬼������ĳ��Ⱥ�λ��
        if( offset )
        {
            site -= offset;
            wide -= offset;
        }
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CImportStream::Assign(CMemory & value) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CImportStream::Swap(CMemory & out) 
{
    //TODO Auto-generated method stub
    bool result = false;
    CCriticalSectionScope scope( clog );
        
    CMemory swap;
    result = swap.Alloc( static_cast<size_t>(wide) );
    if( result )
    {
        // ���ȷ����ڴ棬��data�ڵ����ݿ���������
        U64 offset = 0;
        for( CImportStreamBind::iterator 
            it = data.begin(); it != data.end(); ++ it )
        {
            memcpy( swap.Query<char>() + offset, it -> Query<char>(), it -> GetLength() );
            offset += it -> GetLength();
        }
        swap.SetLength( static_cast<size_t>(wide) );
            
        // ���������֮������data��ص����ݣ�
        site = 0;
        wide = out.GetLength();

        data.clear();
        if( out.GetLength() ) data.push_back( out );                
            
        // ��swap����block��
        out = swap;
    }
    return result;
}
