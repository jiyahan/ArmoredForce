#ifndef CIMPORTSTREAM_H
#define CIMPORTSTREAM_H
//Begin section for file CImportStream.h
//TODO: Add definitions that you want preserved
//End section for file CImportStream.h
#include "../../interface/IImportStream.h"
#include "../../interface/IInterface.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../os/memory/CMemory.h"
#include "CImportStreamBind.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CImportStream : public IImportStream
    {

        //Begin section for atom::CImportStream
        //TODO: Add attributes that you want preserved
        //End section for atom::CImportStream

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif

			
			
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection clog;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 site;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 wide;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportStreamBind data;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportStream(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CImportStream(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int IncRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int DecRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int GetRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetNest(IInterface * nest); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual char Read(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 Read(void * value, U64 length); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 Read(void * value, U64 offset, U64 length); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Close(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 Available(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Mark(U64 position); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Reset(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual I64 Skip(I64 bytes); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Truncate(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Assign(CMemory & data); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Swap(CMemory & data); 



    };  //end class CImportStream


}//end namespace atom


#endif
