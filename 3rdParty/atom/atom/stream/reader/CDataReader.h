#ifndef CDATAREADER_H
#define CDATAREADER_H
//Begin section for file CDataReader.h
//TODO: Add definitions that you want preserved
//End section for file CDataReader.h
#include "../../interface/IInterface.h"
#include "../wrapper/CClosableWrapper.h"
#include "../wrapper/CSwappableWrapper.h"
#include "../wrapper/CAssignableWrapper.h"
#include "../wrapper/CTruncatableWrapper.h"
#include "../wrapper/CImportableWrapper.h"
#include "../../os/memory/CMemory.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"



namespace atom
{



    //<p>This class is not thread safe. If use this class in multi-thread environment, must use critical section to protect it.</p>
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CDataReader : public IInterface
    {

        //Begin section for atom::CDataReader
        //TODO: Add attributes that you want preserved
        //End section for atom::CDataReader

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CClosableWrapper closable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CSwappableWrapper swappable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CAssignableWrapper assignable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CTruncatableWrapper truncatable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportableWrapper importable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * bind;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CDataReader(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CDataReader(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Attach(IInterface * bind); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Detach(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Assign(CMemory & data); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Close(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Swap(CMemory & data); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Truncate(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            I08 ReadI08(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            I16 ReadI16(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            I32 ReadI32(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            I64 ReadI64(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U08 ReadU08(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U16 ReadU16(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U32 ReadU32(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 ReadU64(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            float ReadFloat(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            double ReadDouble(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_string ReadString(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_string ReadUtf8String(); 

			
			
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            a_wstring ReadWString(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 ReadBytes(void * bytes, U64 length); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void SkipBytes(I64 count); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             U64 Available(); 



    };  //end class CDataReader


}//end namespace atom


#endif
