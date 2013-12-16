#include "internet.h"
#include "../../../byteswap/CByteSwap.h"

U16 internet_checksum(void* buffer, U64 length)
{
    U32 result = 0;
    if( buffer && length )
    {
        // 将来源的数据视作网络字节序，在本地进行计算；
        U64 offset(0), amount( length / sizeof(U16) ); 
        for( ; offset < amount; ++ offset ) {
            result += atom::CByteSwap::ntoh( 
                ( reinterpret_cast<U16*>(buffer) )[offset] );
        }

        offset = offset * sizeof( U16 );
        for( ; offset < length; ++ offset ) {
            result += ( reinterpret_cast<U08*>(buffer) )[offset];
        }

        result  = ( result >> 16 ) + ( result & 0xffff );
        result += ( result >> 16 );
    }
    return static_cast<U16>( ~result );
}
