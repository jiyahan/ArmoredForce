#ifndef CIMPORTER_H
#define CIMPORTER_H
//Begin section for file CImporter.h
//TODO: Add definitions that you want preserved
//End section for file CImporter.h
#include "../../interface/IInterface.h"
#include "../memory/CImportStream.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CImporter : public IInterface
    {

        //Begin section for atom::CImporter
        //TODO: Add attributes that you want preserved
        //End section for atom::CImporter

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportStream stream;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImporter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CImporter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CImporter


}//end namespace atom


#endif
