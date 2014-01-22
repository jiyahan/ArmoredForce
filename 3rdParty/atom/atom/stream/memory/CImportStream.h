#ifndef CIMPORTSTREAM_H
#define CIMPORTSTREAM_H
#include "../../interface/IImportStream.h"
#include "../../interface/IInterface.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../os/memory/CMemory.h"
#include "CImportStreamBind.h"



namespace atom
{



    class CImportStream : public IImportStream
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            CCriticalSection clog;



            U64 site;



            U64 wide;



            CImportStreamBind data;




        public:

            CImportStream(); 



            virtual ~CImportStream(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual char Read(); 



            virtual U64 Read(void * value, U64 length); 



            virtual U64 Read(void * value, U64 offset, U64 length); 



            virtual void Close(); 



            virtual U64 Available(); 



            virtual void Mark(U64 position); 



            virtual void Reset(); 



            virtual I64 Skip(I64 bytes); 



            virtual void Truncate(); 



            virtual bool Assign(CMemory & data); 



            virtual bool Swap(CMemory & data); 



    };  //end class CImportStream


}//end namespace atom


#endif
