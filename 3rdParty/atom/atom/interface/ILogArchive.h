#ifndef ILOGARCHIVE_H
#define ILOGARCHIVE_H
//Begin section for file ILogArchive.h
//TODO: Add definitions that you want preserved
//End section for file ILogArchive.h
#include "IEmbedInterface.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class ILogArchive : public IEmbedInterface
    {

        //Begin section for atom::ILogArchive
        //TODO: Add attributes that you want preserved
        //End section for atom::ILogArchive



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Append(const char * value) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Finish(U08 level) = 0; 



    };  //end class ILogArchive



} //end namespace atom



#endif
