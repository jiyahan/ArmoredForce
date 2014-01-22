#ifndef IEXPORTABLE_H
#define IEXPORTABLE_H
#include "IEmbedInterface.h"



namespace atom
{



     class IExportable : public IEmbedInterface
     {




         public:

             virtual void Write(I08 value) = 0; 



             virtual void Write(I16 value) = 0; 



             virtual void Write(I32 value) = 0; 



             virtual void Write(I64 value) = 0; 



             virtual void Write(U08 value) = 0; 



             virtual void Write(U16 value) = 0; 



             virtual void Write(U32 value) = 0; 



             virtual void Write(U64 value) = 0; 



             virtual void Write(float value) = 0; 



             virtual void Write(double value) = 0; 



             virtual void Write(const char * value) = 0; 



             virtual void Write(const wchar_t * value) = 0; 



             virtual void Write(const void * bytes, U64 length) = 0; 



     };  //end class IExportable


}//end namespace atom


#endif
