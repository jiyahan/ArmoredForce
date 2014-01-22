#ifndef IIMPORTABLE_H
#define IIMPORTABLE_H
#include "IEmbedInterface.h"
#include "../utility/stl/a_string.h"
#include "../utility/stl/a_wstring.h"



namespace atom
{



     class IImportable : public IEmbedInterface
     {




         public:

             virtual I08 ReadI08() = 0; 



             virtual I16 ReadI16() = 0; 



             virtual I32 ReadI32() = 0; 



             virtual I64 ReadI64() = 0; 



             virtual U08 ReadU08() = 0; 



             virtual U16 ReadU16() = 0; 



             virtual U32 ReadU32() = 0; 



             virtual U64 ReadU64() = 0; 



             virtual float ReadFloat() = 0; 



             virtual double ReadDouble() = 0; 



             virtual a_string ReadString() = 0; 



             virtual a_string ReadUtf8String() = 0; 

			 
			 
             virtual a_wstring ReadWString() = 0; 



             virtual U64 ReadBytes(void * bytes, U64 length) = 0; 



             virtual void SkipBytes(I64 count) = 0; 



             virtual U64 Available() = 0; 



     };  //end class IImportable


}//end namespace atom


#endif
