#ifndef CCONNECTORSTUBMAINTAINABLE_H
#define CCONNECTORSTUBMAINTAINABLE_H
//Begin section for file CConnectorStubMaintainable.h
//TODO: Add definitions that you want preserved
//End section for file CConnectorStubMaintainable.h
#include "../Common.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CConnectorStubMaintainable : public IMaintainable
    {

        //Begin section for electron::CConnectorStubMaintainable
        //TODO: Add attributes that you want preserved
        //End section for electron::CConnectorStubMaintainable

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubMaintainable(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CConnectorStubMaintainable(); 



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
            virtual U64 OnMaintenance(U64 now); 



    };  //end class CConnectorStubMaintainable



} //end namespace electron



#endif
