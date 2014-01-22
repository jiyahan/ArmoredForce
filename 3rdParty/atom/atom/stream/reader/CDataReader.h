#ifndef CDATAREADER_H
#define CDATAREADER_H
#include "../../interface/IInterface.h"
#include "../wrapper/CClosableWrapper.h"
#include "../wrapper/CSwappableWrapper.h"
#include "../wrapper/CAssignableWrapper.h"
#include "../wrapper/CTruncatableWrapper.h"
#include "../wrapper/CImportableWrapper.h"
#include "../../os/memory/CMemory.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"



namespace atom
{



    //<p>This class is not thread safe. If use this class in multi-thread environment, must use critical section to protect it.</p>
    class CDataReader : public IInterface
    {


        private:


            CClosableWrapper closable;



            CSwappableWrapper swappable;



            CAssignableWrapper assignable;



            CTruncatableWrapper truncatable;



            CImportableWrapper importable;



            IInterface * bind;




        public:

            CDataReader(); 



            virtual ~CDataReader(); 



            virtual IInterface * QueryInterface(U32 iid); 



            void Attach(IInterface * bind); 



            void Detach(); 



            bool Assign(CMemory & data); 



            void Close(); 



            bool Swap(CMemory & data); 



            void Truncate(); 



            I08 ReadI08(); 



            I16 ReadI16(); 



            I32 ReadI32(); 



            I64 ReadI64(); 



            U08 ReadU08(); 



            U16 ReadU16(); 



            U32 ReadU32(); 



            U64 ReadU64(); 



            float ReadFloat(); 



            double ReadDouble(); 



            a_string ReadString(); 



            a_string ReadUtf8String(); 

			
			
            a_wstring ReadWString(); 



            U64 ReadBytes(void * bytes, U64 length); 



            void SkipBytes(I64 count); 



             U64 Available(); 



    };  //end class CDataReader


}//end namespace atom


#endif
