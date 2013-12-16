#ifndef CIMPORTARCHIVE_H
#define CIMPORTARCHIVE_H
//Begin section for file CImportArchive.h
//TODO: Add definitions that you want preserved
//End section for file CImportArchive.h
#include "../interface/IEmbedInterface.h"
#include "../interface/IInterface.h"
#include "../utility/stl/a_string.h"
#include "../utility/stl/a_wstring.h"
#include "tagSerializer.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CImportArchive : public IEmbedInterface
    {

        //Begin section for atom::CImportArchive
        //TODO: Add attributes that you want preserved
        //End section for atom::CImportArchive

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportArchive(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CImportArchive(); 



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
            void Bind(bool & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(char & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I08 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I16 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I32 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I64 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U08 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U16 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U32 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U64 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(float & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(double & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(a_string & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(a_wstring & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(void * buffer, U64 length); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            void Bind(T & value)
            {
                //TODO Auto-generated method stub
	            tagSerializer<CImportArchive, T, false>::Serialize( *this, value );
            }



    };  //end class CImportArchive



} //end namespace atom



#endif
