#ifndef IINSTANCECONTAINER_H
#define IINSTANCECONTAINER_H
//Begin section for file IInstanceContainer.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceContainer.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{


    
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IInstanceContainer : public IEmbedInterface
    {

        //Begin section for atom::IInstanceContainer
        //TODO: Add attributes that you want preserved
        //End section for atom::IInstanceContainer



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Insert(CObjectPtr & instance) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual CObjectPtr Obtain(U64 instance_name) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Obtain(CU64Array & instances) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Inside(U64 instance_name) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64 Amount() = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Remove(U64 instance_name) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void RemoveAll() = 0; 



    };  //end class IInstanceContainer


} //end namespace atom



#endif
