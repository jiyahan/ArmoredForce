#ifndef IASSIGNABLE_H
#define IASSIGNABLE_H
//Begin section for file IAssignable.h
//TODO: Add definitions that you want preserved
//End section for file IAssignable.h
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
 {



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IAssignable : public IEmbedInterface
     {

         //Begin section for atom::IAssignable
         //TODO: Add attributes that you want preserved
         //End section for atom::IAssignable



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Assign(CMemory & data) = 0; 



     };  //end class IAssignable


 }//end namespace atom


#endif
