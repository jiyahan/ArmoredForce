#ifndef CEXPORTSTREAM_H
#define CEXPORTSTREAM_H
#include "../../interface/IExportStream.h"
#include "../../interface/IInterface.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../os/memory/CMemory.h"



namespace atom
{



    class CExportStream : public IExportStream
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            CCriticalSection clog;



            CMemory data;



            bool Resize(size_t size); 



            bool CheckCapacity(size_t size); 




        public:

            CExportStream(); 



            virtual ~CExportStream(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Write(char value); 



            virtual void Write(const void * value, U64 length); 



            virtual void Write(const void * value, U64 offset, U64 length); 



            virtual void Close(); 



            virtual void Flush(); 



            virtual U64 Length(); 



            virtual bool Clone(CMemory & data); 



            virtual bool Swap(CMemory & data); 



    };  //end class CExportStream


}//end namespace atom


#endif
