#ifndef CTCPNETWORKSERVICECONTROLLER_H
#define CTCPNETWORKSERVICECONTROLLER_H
//Begin section for file CTcpNetworkServiceController.h
//TODO: Add definitions that you want preserved
//End section for file CTcpNetworkServiceController.h
#include "../../interface/ITcpNetworkServiceController.h"
#include "../../interface/IInterface.h"
#include "CTcpNetworkServiceControllerBind.h"
#include "../thread/CCriticalSection.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CTcpNetworkServiceController : public ITcpNetworkServiceController
	{

		//Begin section for atom::CTcpNetworkServiceController
		//TODO: Add attributes that you want preserved
		//End section for atom::CTcpNetworkServiceController

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IInterface * nest;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpNetworkServiceControllerBind mapping;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CCriticalSection section;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			CTcpNetworkServiceController(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual ~CTcpNetworkServiceController(); 



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
			virtual bool Initiate(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual bool Shutdown(); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			virtual CObjectPtr GetModel(U32 io_model); 



	};  //end class CTcpNetworkServiceController



} //end namespace atom



#endif
