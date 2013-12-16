#ifndef IFILESTREAM_H
#define IFILESTREAM_H
//Begin section for file IFileStream.h
//TODO: Add definitions that you want preserved
//End section for file IFileStream.h
#include "IStream.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IFileStream : public IStream
    {

        //Begin section for atom::IFileStream
        //TODO: Add attributes that you want preserved
        //End section for atom::IFileStream



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Open() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool IsReadOnly() = 0; 



    };  //end class IFileStream


}//end namespace atom


#endif
