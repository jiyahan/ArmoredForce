#include "CBase64Codec.h"


bool atom::CBase64Codec::Encode(CMemory & source, CMemory & target) 
{
    // encode table
    static const char table[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=" };

    bool result = false;
    if( source.GetLength() )
    {
        // 获取源缓冲区的指针以及长度；
        size_t src_len = source.GetLength(), tgt_len(0);
        const U08 * src_ptr = source.Query<U08>();

        // 求目标缓冲区的长度；
        ( src_len % 3 ) > 0 ? 
            tgt_len = 4 * ( src_len / 3 + 1 ) :
            tgt_len = 4 * ( src_len / 3 );

        // 分配内存；
        if( target.Alloc(tgt_len + 1) )
        {
            target.SetLength( tgt_len );

            memset( target, 0, tgt_len + 1 );
            U08 * tgt_ptr = target.Query<U08>();

            size_t offset = 0;
            size_t i = 0, j = src_len - 3;
            for( ; i <= j; i += 3 )
            {
                tgt_ptr[offset + 0] = ( (src_ptr[i + 0] >> 2) );
                tgt_ptr[offset + 1] = ( (src_ptr[i + 0] & 0x03) << 4 ) | ( src_ptr[i + 1] >> 4 );
                tgt_ptr[offset + 2] = ( (src_ptr[i + 1] & 0x0f) << 2 ) | ( src_ptr[i + 2] >> 6 );
                tgt_ptr[offset + 3] = ( (src_ptr[i + 2] & 0x3f) );
                offset += 4;
            }

            switch( src_len % 3 )
            {
            case 1:
                tgt_ptr[offset+0] = ( (src_ptr[i] >> 2) );
                tgt_ptr[offset+1] = ( (src_ptr[i] & 0x03) << 4 ) ;
                tgt_ptr[offset+2] = 64;
                tgt_ptr[offset+3] = 64;
                break;
            case 2:
                tgt_ptr[offset+0] = ( (src_ptr[i + 0] >> 2) );
                tgt_ptr[offset+1] = ( (src_ptr[i + 0] & 0x03) << 4 ) | ( src_ptr[i + 1] >> 4 );
                tgt_ptr[offset+2] = ( (src_ptr[i + 1] & 0x0f) << 2 );
                tgt_ptr[offset+3] = 64;
                break;
            }

            for( i = 0; i < tgt_len; ++ i ) {
                tgt_ptr[i] = table[tgt_ptr[i]];
            }

            result = true;
        }
    }
    return result;
}

bool atom::CBase64Codec::Decode(CMemory & source, CMemory & target) 
{
    // decode table
    static const char table[] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

        // +
        62, 0, 0, 0,

        // /
        63, 

        // 0 - 9
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 

        // A - Z
        0, 0, 0, 0, 0, 0, 0,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 

        // a - z
        0, 0, 0, 0, 0, 0,
        26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
        39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
    };

    bool result = false;
    size_t src_len = source.GetLength();
    if( src_len && (src_len % 4) == 0 )
    {
        CMemory buffer;
        if( buffer.Alloc(src_len) )
        {
            size_t tgt_len = src_len / 4 * 3;
            if( target.Alloc(tgt_len) )
            {
                const 
                U08 * src_ptr = source.Query<U08>();
                U08 * buf_ptr = buffer.Query<U08>();
                U08 * tgt_ptr = target.Query<U08>();

                size_t i = 0, j = 0;
                unsigned char offset;
                for( ; i < src_len; ++ i ) {
                    offset = src_ptr[i];
                    if( offset < sizeof(table) ) buf_ptr[i] = table[offset];
                }

                for( i = 0; i < src_len; i += 4 )
                {
                    tgt_ptr[j + 0] = ( buf_ptr[i + 0] << 2 ) | ( buf_ptr[i + 1] >> 4 );
                    tgt_ptr[j + 1] = ( buf_ptr[i + 1] << 4 ) | ( buf_ptr[i + 2] >> 2 );
                    tgt_ptr[j + 2] = ( buf_ptr[i + 2] << 6 ) | ( buf_ptr[i + 3] );
                    j += 3;
                }

                if( src_ptr[src_len - 1] == '=' ) -- tgt_len;
                if( src_ptr[src_len - 2] == '=' ) -- tgt_len;

                target.SetLength( tgt_len ); result = true;
            }
        }
    }
    return result;
}
