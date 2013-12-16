#ifndef CLOGSERVICELIFE_H
#define CLOGSERVICELIFE_H
//Begin section for file CLogServiceLife.h
//TODO: Add definitions that you want preserved
//End section for file CLogServiceLife.h
#include "../interface/IInstanceLife.h"
#include "../interface/IInterface.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CLogServiceLife : public IInstanceLife
    {

        //Begin section for atom::CLogServiceLife
        //TODO: Add attributes that you want preserved
        //End section for atom::CLogServiceLife

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLogServiceLife(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CLogServiceLife(); 



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



    };  //end class CLogServiceLife



} //end namespace atom



#endif
