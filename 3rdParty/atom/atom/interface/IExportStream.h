#ifndef IEXPORTSTREAM_H
#define IEXPORTSTREAM_H
//Begin section for file IExportStream.h
//TODO: Add definitions that you want preserved
//End section for file IExportStream.h
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class IExportStream : public IEmbedInterface
     {

         //Begin section for atom::IExportStream
         //TODO: Add attributes that you want preserved
         //End section for atom::IExportStream



         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Write(char value) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Write(const void * value, U64 length) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Write(const void * value, U64 offset, U64 length) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Close() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual void Flush() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual U64 Length() = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Clone(CMemory & data) = 0; 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             virtual bool Swap(CMemory & data) = 0; 



     };  //end class IExportStream


}//end namespace atom


#endif
