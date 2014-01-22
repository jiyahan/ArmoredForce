#ifndef CSTREAM_H
#define CSTREAM_H
#include "../../interface/IStream.h"
#include "../../interface/IInterface.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../os/memory/CMemory.h"




namespace atom
{



    class CStream : public IStream
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif

			
			
            CCriticalSection clog;



            U64 site;



            CMemory data;



            bool Resize(size_t size); 



            bool CheckCapacity(size_t size); 




        public:

            CStream(); 



            virtual ~CStream(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual char Read(); 



            virtual U64 Read(void * value, U64 length); 



            virtual U64 Read(void * value, U64 offset, U64 length); 



            virtual void Write(char value); 



            virtual void Write(const void * value, U64 length); 



            virtual void Write(const void * value, U64 offset, U64 length); 



            virtual void Close(); 



            virtual void Truncate(); 



            virtual void Flush(); 



            virtual U64 Available(); 



            virtual U64 Length(); 



            virtual void Mark(U64 position); 



            virtual void Reset(); 



            virtual I64 Skip(I64 bytes); 



            virtual bool Assign(CMemory & data); 



            virtual bool Swap(CMemory & data); 



            virtual bool Clone(CMemory & data); 



    };  //end class CStream


}//end namespace atom


#endif
