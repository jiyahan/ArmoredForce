#ifndef ISWAPPABLE_H
#define ISWAPPABLE_H
//Begin section for file ISwappable.h
//TODO: Add definitions that you want preserved
//End section for file ISwappable.h
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class ISwappable : public IEmbedInterface
     {

         //Begin section for atom::ISwappable
         //TODO: Add attributes that you want preserved
         //End section for atom::ISwappable



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Swap(CMemory & data) = 0; 



     };  //end class ISwappable


}//end namespace atom


#endif
