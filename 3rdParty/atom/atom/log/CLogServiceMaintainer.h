#ifndef CLOGSERVICEMAINTAINER_H
#define CLOGSERVICEMAINTAINER_H
//Begin section for file CLogServiceMaintainer.h
//TODO: Add definitions that you want preserved
//End section for file CLogServiceMaintainer.h
#include "../interface/IMaintainable.h"
#include "../interface/IInterface.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CLogServiceMaintainer : public IMaintainable
    {

        //Begin section for atom::CLogServiceMaintainer
        //TODO: Add attributes that you want preserved
        //End section for atom::CLogServiceMaintainer

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLogServiceMaintainer(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CLogServiceMaintainer(); 



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



    };  //end class CLogServiceMaintainer



} //end namespace atom



#endif
