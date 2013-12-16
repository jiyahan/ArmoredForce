#ifndef IEMBEDINTERFACE_H
#define IEMBEDINTERFACE_H
//Begin section for file IEmbedInterface.h
//TODO: Add definitions that you want preserved
//End section for file IEmbedInterface.h
#include "IReferencedInterface.h"
#include "IInterface.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IEmbedInterface : public IReferencedInterface
     {

         //Begin section for atom::IEmbedInterface
         //TODO: Add attributes that you want preserved
         //End section for atom::IEmbedInterface



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void SetNest(IInterface * nest) = 0; 



     };  //end class IEmbedInterface


}//end namespace atom


#endif
