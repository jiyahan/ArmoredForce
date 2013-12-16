#ifndef CCONNECTIONSCHEDULEREVENTRECEIVER_H
#define CCONNECTIONSCHEDULEREVENTRECEIVER_H
//Begin section for file CConnectionSchedulerEventReceiver.h
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerEventReceiver.h
#include "../Common.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CConnectionSchedulerEventReceiver : public IEventReceiver
    {

        //Begin section for electron::CConnectionSchedulerEventReceiver
        //TODO: Add attributes that you want preserved
        //End section for electron::CConnectionSchedulerEventReceiver

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerEventReceiver(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CConnectionSchedulerEventReceiver(); 



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



    };  //end class CConnectionSchedulerEventReceiver



} //end namespace electron



#endif
