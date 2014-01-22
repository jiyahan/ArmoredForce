#ifndef CIMPORTABLEWRAPPER_H
#define CIMPORTABLEWRAPPER_H
#include "../../interface/IImportable.h"
#include "../../interface/IInterface.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IStream.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"
#include "tagWrapper.h"



namespace atom
{



    class CImportableWrapper : public IImportable
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            IInterface * bind;



			tagWrapper port;



            U32 wrap;




        public:

            CImportableWrapper(); 



            virtual ~CImportableWrapper(); 



            void Verify(); 



            void Attach(IInterface * nest); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual I08 ReadI08(); 



            virtual I16 ReadI16(); 



            virtual I32 ReadI32(); 



            virtual I64 ReadI64(); 



            virtual U08 ReadU08(); 



            virtual U16 ReadU16(); 



            virtual U32 ReadU32(); 



            virtual U64 ReadU64(); 



            virtual float ReadFloat(); 



            virtual double ReadDouble(); 



            virtual a_string ReadString(); 



            virtual a_string ReadUtf8String(); 

			 
			 
            virtual a_wstring ReadWString(); 



            virtual U64 ReadBytes(void * bytes, U64 length); 



            virtual void SkipBytes(I64 count); 



             virtual U64 Available(); 



    };  //end class CImportableWrapper


}//end namespace atom


#endif
