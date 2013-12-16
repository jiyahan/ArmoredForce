#ifndef CCONNECTORSTUBEVENTRECEIVER_H
#define CCONNECTORSTUBEVENTRECEIVER_H
//Begin section for file CConnectorStubEventReceiver.h
//TODO: Add definitions that you want preserved
//End section for file CConnectorStubEventReceiver.h
#include "../Common.h"



namespace electron
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CConnectorStubEventReceiver : public IEventReceiver
    {

        //Begin section for electron::CConnectorStubEventReceiver
        //TODO: Add attributes that you want preserved
        //End section for electron::CConnectorStubEventReceiver

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectorStubEventReceiver(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CConnectorStubEventReceiver(); 



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
            virtual bool OnEvent(const tagEvent & event); 



    };  //end class CConnectorStubEventReceiver



} //end namespace electron



#endif
