#ifndef IIMPORTABLE_H
#define IIMPORTABLE_H
//Begin section for file IImportable.h
//TODO: Add definitions that you want preserved
//End section for file IImportable.h
#include "IEmbedInterface.h"
#include "../utility/stl/a_string.h"
#include "../utility/stl/a_wstring.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IImportable : public IEmbedInterface
     {

         //Begin section for atom::IImportable
         //TODO: Add attributes that you want preserved
         //End section for atom::IImportable



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual I08 ReadI08() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual I16 ReadI16() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual I32 ReadI32() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual I64 ReadI64() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U08 ReadU08() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U16 ReadU16() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U32 ReadU32() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 ReadU64() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual float ReadFloat() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual double ReadDouble() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual a_string ReadString() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual a_string ReadUtf8String() = 0; 

			 
			 
			 //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual a_wstring ReadWString() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 ReadBytes(void * bytes, U64 length) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void SkipBytes(I64 count) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 Available() = 0; 



     };  //end class IImportable


}//end namespace atom


#endif
