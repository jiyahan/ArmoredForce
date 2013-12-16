#ifndef ATOM_SERIALIZATION_H
#define ATOM_SERIALIZATION_H
#include "../../Common.h"
#include "../../os/memory/CMemory.h"
#include "../../utility/checksum/alogrithm/internet/internet.h"



template<class Archive>
inline void Serialize(Archive & archive, atom::CMemory & block, bool isSave)
{
	if( isSave )
	{
		U32 bound = static_cast<U32>( block.GetLength() );
        U16 check = internet_checksum( & bound, sizeof(bound) );

		archive.Bind( bound );
        archive.Bind( check );

		if( bound ) {
			archive.Bind( block, bound );
		}
	}
	else
	{
		U32 bound = 0;
        U16 check = 0;

		archive.Bind( bound );
        archive.Bind( check );

        // does checksum correct ?
        if( check == internet_checksum( & bound, sizeof(bound) ) )
        {
            if( bound && block.Alloc(bound + 1) )
		    {
                memset( block, 0, block.GetCapacity() );
			    archive.Bind( block, bound );
			    block.SetLength( bound );
		    }
        }

        // 出错，输出日志；
        else
        {
        }
	}
}

#endif
