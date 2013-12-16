#ifndef CTCPCONNECTORFLUSHQUEUE_H
#define CTCPCONNECTORFLUSHQUEUE_H
//Begin section for file CTcpConnectorFlushQueue.h
//TODO: Add definitions that you want preserved
//End section for file CTcpConnectorFlushQueue.h
#include "../thread/CCriticalSection.h"
#include "../memory/CMemory.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpConnectorFlushQueue
	{

		//Begin section for atom::CTcpConnectorFlushQueue
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpConnectorFlushQueue

		public:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			typedef std::list<CMemory, atom_allocator<CMemory> >  CTcpConnectorFlushQueueBind ;

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t length;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t offset;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorFlushQueueBind queued;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection section;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorFlushQueue(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpConnectorFlushQueue(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Clear(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool IsEmpty(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			void Append(CMemory & data); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Obtain(CMemory & data, size_t & offset); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t Length(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool Change(CTcpConnectorFlushQueueBind & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			bool IncreaseOffset(size_t value); 



	};  //end class CTcpConnectorFlushQueue



} //end namespace atom



#endif
