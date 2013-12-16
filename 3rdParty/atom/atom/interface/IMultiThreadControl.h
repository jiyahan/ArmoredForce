#ifndef IMULTITHREADCONTROL_H
#define IMULTITHREADCONTROL_H
//Begin section for file IMultiThreadControl.h
//TODO: Add definitions that you want preserved
//End section for file IMultiThreadControl.h
#include "IThreadControl.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IMultiThreadControl : public IThreadControl
    {

        //Begin section for atom::IMultiThreadControl
        //TODO: Add attributes that you want preserved
        //End section for atom::IMultiThreadControl



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnBegin(U32 index) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnClose(U32 index) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnAwake(U32 index) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetThreadAmount(U32 index) = 0; 
            


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U32 GetThreadAmount() = 0; 



    };  //end class IMultiThreadControl



} //end namespace atom



#endif
