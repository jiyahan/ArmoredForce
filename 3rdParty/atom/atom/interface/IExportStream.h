#ifndef IEXPORTSTREAM_H
#define IEXPORTSTREAM_H
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     class IExportStream : public IEmbedInterface
     {




         public:

             virtual void Write(char value) = 0; 



             virtual void Write(const void * value, U64 length) = 0; 



             virtual void Write(const void * value, U64 offset, U64 length) = 0; 



             virtual void Close() = 0; 



             virtual void Flush() = 0; 



             virtual U64 Length() = 0; 



             virtual bool Clone(CMemory & data) = 0; 



             virtual bool Swap(CMemory & data) = 0; 



     };  //end class IExportStream


}//end namespace atom


#endif
