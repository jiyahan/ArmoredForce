#ifndef ILOGSERVICECONTROLLER_H
#define ILOGSERVICECONTROLLER_H
//Begin section for file ILogServiceController.h
//TODO: Add definitions that you want preserved
//End section for file ILogServiceController.h
#include "IEmbedInterface.h"
#include "IInterface.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class ILogServiceController : public IEmbedInterface
    {

        //Begin section for atom::ILogServiceController
        //TODO: Add attributes that you want preserved
        //End section for atom::ILogServiceController



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Setup(U08 display_level, IInterface * output) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Clear() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Write(U08 level, const char * log) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Flush() = 0; 



    };  //end class ILogServiceController



} //end namespace atom



#endif
