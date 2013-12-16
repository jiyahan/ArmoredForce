#ifndef CARCHIVE_H
#define CARCHIVE_H
//Begin section for file CArchive.h
//TODO: Add definitions that you want preserved
//End section for file CArchive.h
#include "../Common.h"
#include "../os/memory/CMemory.h"
#include "../interface/IInterface.h"
#include "../stream/memory/CStream.h"
#include "../stream/wrapper/CImportableWrapper.h"
#include "../stream/wrapper/CExportableWrapper.h"
#include "CExportArchive.h"
#include "CImportArchive.h"


namespace atom
{
    

    
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CArchive : public IInterface
    {

        //Begin section for atom::CArchive
        //TODO: Add attributes that you want preserved
        //End section for atom::CArchive

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CStream stream;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportableWrapper importable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CExportableWrapper exportable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CExportArchive export_archive;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportArchive import_archive;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CArchive(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CArchive(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Assign(CMemory & data); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Clone(CMemory & data); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Clear(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            inline CArchive & operator <<(T & value)
            {
                //TODO Auto-generated method stub
                export_archive.Bind( value );
                return( *this );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            inline CArchive & operator <<(const T & value)
            {
                //TODO Auto-generated method stub
                export_archive.Bind( value );
                return( *this );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            inline CArchive & operator >>(T & value)
            {
                //TODO Auto-generated method stub
                import_archive.Bind( value );
                return( *this );
            }



    };  //end class CArchive



} //end namespace atom



#endif
