#ifndef CTCPCONNECTORFLUSHQUEUE_H
#define CTCPCONNECTORFLUSHQUEUE_H
#include "../thread/CCriticalSection.h"
#include "../memory/CMemory.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



	class CTcpConnectorFlushQueue
	{


		public:


			typedef std::list<CMemory, atom_allocator<CMemory> >  CTcpConnectorFlushQueueBind ;

		private:


			size_t length;



			size_t offset;



			CTcpConnectorFlushQueueBind queued;



			CCriticalSection section;




		public:

			CTcpConnectorFlushQueue(); 



			virtual ~CTcpConnectorFlushQueue(); 



			void Clear(); 



			bool IsEmpty(); 



			void Append(CMemory & data); 



			bool Obtain(CMemory & data, size_t & offset); 



			size_t Length(); 



			bool Change(CTcpConnectorFlushQueueBind & value); 



			bool IncreaseOffset(size_t value); 



	};  //end class CTcpConnectorFlushQueue



} //end namespace atom



#endif
