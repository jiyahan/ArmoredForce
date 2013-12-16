#ifndef CCONNECTIONSCHEDULERMULTITHREADWORKER_H
#define CCONNECTIONSCHEDULERMULTITHREADWORKER_H
//Begin section for file CConnectionSchedulerMultiThreadWorker.h
//TODO: Add definitions that you want preserved
//End section for file CConnectionSchedulerMultiThreadWorker.h
#include "../Common.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CConnectionSchedulerMultiThreadWorker : public CThread
    {

        //Begin section for electron::CConnectionSchedulerMultiThreadWorker
        //TODO: Add attributes that you want preserved
        //End section for electron::CConnectionSchedulerMultiThreadWorker

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U32 serial;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool active;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CObjectPtr object;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CSignal signal;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CConnectionSchedulerMultiThreadWorker(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CConnectionSchedulerMultiThreadWorker(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U32 Run(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnThreadBegin(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnThreadClose(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void SetObject(CObjectPtr & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void SetActive(bool value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void SetAwaken(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void SetSerial(U32 serial); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool GetActive();



    };  //end class CConnectionSchedulerMultiThreadWorker



} //end namespace electron



#endif
