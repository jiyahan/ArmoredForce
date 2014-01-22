#ifndef CDATAWRITER_H
#define CDATAWRITER_H
#include "../../interface/IInterface.h"
#include "../wrapper/CClosableWrapper.h"
#include "../wrapper/CSwappableWrapper.h"
#include "../wrapper/CClonableWrapper.h"
#include "../wrapper/CFlushableWrapper.h"
#include "../wrapper/CExportableWrapper.h"
#include "../../os/memory/CMemory.h"



namespace atom
{



    class CDataWriter : public IInterface
    {


        private:


            IInterface * bind;



            CClosableWrapper closable;



            CSwappableWrapper swappable;



            CClonableWrapper clonable;



            CFlushableWrapper flushable;



            CExportableWrapper exportable;




        public:

            CDataWriter(); 



            virtual ~CDataWriter(); 



            virtual IInterface * QueryInterface(U32 iid); 



            void Attach(IInterface * bind); 



            void Detach(); 



            void Write(I08 value); 



            void Write(I16 value); 



            void Write(I32 value); 



            void Write(I64 value); 



            void Write(U08 value); 



            void Write(U16 value); 



            void Write(U32 value); 



            void Write(U64 value); 



            void Write(float value); 



            void Write(double value); 



            void Write(const char * value); 



            void Write(const wchar_t * value); 



            void Write(const void * bytes, U64 length); 



            void Close(); 



            void Flush(); 



            bool Clone(CMemory & data); 



            bool Swap(CMemory & data); 



    };  //end class CDataWriter


}//end namespace atom


#endif
