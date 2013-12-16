#ifndef ICLONABLE_H
#define ICLONABLE_H
//Begin section for file IClonable.h
//TODO: Add definitions that you want preserved
//End section for file IClonable.h
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IClonable : public IEmbedInterface
     {

         //Begin section for atom::IClonable
         //TODO: Add attributes that you want preserved
         //End section for atom::IClonable



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Clone(CMemory & data) = 0; 



     };  //end class IClonable


}//end namespace atom


#endif
