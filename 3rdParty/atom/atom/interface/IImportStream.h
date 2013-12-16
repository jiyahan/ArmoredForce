#ifndef IIMPORTSTREAM_H
#define IIMPORTSTREAM_H
//Begin section for file IImportStream.h
//TODO: Add definitions that you want preserved
//End section for file IImportStream.h
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IImportStream : public IEmbedInterface
     {

         //Begin section for atom::IImportStream
         //TODO: Add attributes that you want preserved
         //End section for atom::IImportStream



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual char Read() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 Read(void * value, U64 length) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 Read(void * value, U64 offset, U64 length) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Close() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 Available() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Mark(U64 position) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Reset() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual I64 Skip(I64 bytes) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Truncate() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Assign(CMemory & data) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Swap(CMemory & data) = 0; 



     };  //end class IImportStream


}//end namespace atom


#endif
