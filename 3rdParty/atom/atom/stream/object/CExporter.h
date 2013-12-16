#ifndef CEXPORTER_H
#define CEXPORTER_H
//Begin section for file CExporter.h
//TODO: Add definitions that you want preserved
//End section for file CExporter.h
#include "../../interface/IInterface.h"
#include "../memory/CExportStream.h"




namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CExporter : public IInterface
    {

        //Begin section for atom::CExporter
        //TODO: Add attributes that you want preserved
        //End section for atom::CExporter

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CExportStream stream;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CExporter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CExporter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CExporter


}//end namespace atom


#endif
