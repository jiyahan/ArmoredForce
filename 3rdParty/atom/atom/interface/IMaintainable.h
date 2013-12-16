#ifndef IMAINTAINABLE_H
#define IMAINTAINABLE_H
//Begin section for file IMaintainable.h
//TODO: Add definitions that you want preserved
//End section for file IMaintainable.h
#include "IEmbedInterface.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IMaintainable : public IEmbedInterface
     {

         //Begin section for atom::IMaintainable
         //TODO: Add attributes that you want preserved
         //End section for atom::IMaintainable



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 OnMaintenance(U64 now) = 0; 



     };  //end class IMaintainable


}//end namespace atom


#endif
