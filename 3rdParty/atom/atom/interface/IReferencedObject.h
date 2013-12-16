#ifndef IREFERENCEDOBJECT_H
#define IREFERENCEDOBJECT_H
//Begin section for file IReferencedObject.h
//TODO: Add definitions that you want preserved
//End section for file IReferencedObject.h
#include "IReferencedInterface.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IReferencedObject : public IReferencedInterface
     {

         //Begin section for atom::IReferencedObject
         //TODO: Add attributes that you want preserved
         //End section for atom::IReferencedObject



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void SetName(U64 name) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 GetName() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void SetType(U32 type) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U32 GetType() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual const char * ToString() = 0; 



     };  //end class IReferencedObject


}//end namespace atom


#endif
