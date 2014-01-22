#ifndef CEXPORTABLEWRAPPER_H
#define CEXPORTABLEWRAPPER_H
#include "../../interface/IExportable.h"
#include "../../interface/IInterface.h"
#include "../../interface/IExportStream.h"
#include "../../interface/IStream.h"
#include "tagWrapper.h"



namespace atom
{



    class CExportableWrapper : public IExportable
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

            CExportableWrapper(); 



            virtual ~CExportableWrapper(); 



            void Verify(); 



            void Attach(IInterface * nest); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Write(I08 value); 



            virtual void Write(I16 value); 



            virtual void Write(I32 value); 



            virtual void Write(I64 value); 



            virtual void Write(U08 value); 



            virtual void Write(U16 value); 



            virtual void Write(U32 value); 



            virtual void Write(U64 value); 



            virtual void Write(float value); 



            virtual void Write(double value); 



            virtual void Write(const char * value); 



            virtual void Write(const wchar_t * value); 



            virtual void Write(const void * bytes, U64 length); 



    };  //end class CExportableWrapper


}//end namespace atom


#endif
