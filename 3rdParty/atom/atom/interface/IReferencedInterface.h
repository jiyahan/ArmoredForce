#ifndef IREFERENCEDINTERFACE_H
#define IREFERENCEDINTERFACE_H
//Begin section for file IReferencedInterface.h
//TODO: Add definitions that you want preserved
//End section for file IReferencedInterface.h
#include "IInterface.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IReferencedInterface : public IInterface
     {

         //Begin section for atom::IReferencedInterface
         //TODO: Add attributes that you want preserved
         //End section for atom::IReferencedInterface



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual int IncRef() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual int DecRef() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual int GetRef() = 0; 



     };  //end class IReferencedInterface


}//end namespace atom


#endif
