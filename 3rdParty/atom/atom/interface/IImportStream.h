#ifndef IIMPORTSTREAM_H
#define IIMPORTSTREAM_H
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     class IImportStream : public IEmbedInterface
     {




         public:

             virtual char Read() = 0; 



             virtual U64 Read(void * value, U64 length) = 0; 



             virtual U64 Read(void * value, U64 offset, U64 length) = 0; 



             virtual void Close() = 0; 



             virtual U64 Available() = 0; 



             virtual void Mark(U64 position) = 0; 



             virtual void Reset() = 0; 



             virtual I64 Skip(I64 bytes) = 0; 



             virtual void Truncate() = 0; 



             virtual bool Assign(CMemory & data) = 0; 



             virtual bool Swap(CMemory & data) = 0; 



     };  //end class IImportStream


}//end namespace atom


#endif
