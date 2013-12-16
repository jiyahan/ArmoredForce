#ifndef IINSTANCECONTAINERLISTENER_H
#define IINSTANCECONTAINERLISTENER_H
//Begin section for file IInstanceContainerListener.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceContainerListener.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IInstanceContainerListener : public IEmbedInterface
    {

        //Begin section for atom::IInstanceContainerListener
        //TODO: Add attributes that you want preserved
        //End section for atom::IInstanceContainerListener



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnInsertInstance(CObjectPtr & instance) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnRemoveInstance(CObjectPtr & instance) = 0; 



    };  //end class IInstanceContainerListener



} //end namespace atom



#endif
