#ifndef CTCPCONNECTORFLUSHDEVICE_H
#define CTCPCONNECTORFLUSHDEVICE_H
//Begin section for file CTcpConnectorFlushDevice.h
//TODO: Add definitions that you want preserved
//End section for file CTcpConnectorFlushDevice.h
#include "../../interface/ITcpConnectorFlushDevice.h"
#include "../../interface/IInterface.h"
#include "../thread/CReference.h"
#include "CTcpConnectorFlushQueue.h"
#include "../thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../memory/CMemory.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpConnectorFlushDevice : public ITcpConnectorFlushDevice
	{

		//Begin section for atom::CTcpConnectorFlushDevice
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpConnectorFlushDevice

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CReference counter;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorFlushQueue prepare;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorFlushQueue::CTcpConnectorFlushQueueBind waiting;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection protect;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U64 connect;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CObjectPtr iomodel;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection section;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			size_t Send(); 




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpConnectorFlushDevice(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpConnectorFlushDevice(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int IncRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int DecRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual int GetRef(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual IInterface * QueryInterface(U32 iid); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void SetNest(IInterface * nest); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnFlush(CMemory & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Bind(U32 iomodel); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool OnDataSent(size_t bytes); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual void Reset(); 



	};  //end class CTcpConnectorFlushDevice



} //end namespace atom



#endif
