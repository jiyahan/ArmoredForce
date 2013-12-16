#ifndef CMAINTAINERLISTENER_H
#define CMAINTAINERLISTENER_H
//Begin section for file CMaintainerListener.h
//TODO: Add definitions that you want preserved
//End section for file CMaintainerListener.h
#include "../interface/IInstanceContainerListener.h"
#include "../interface/IInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMaintainerListener : public IInstanceContainerListener
    {

        //Begin section for atom::CMaintainerListener
        //TODO: Add attributes that you want preserved
        //End section for atom::CMaintainerListener

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerListener(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CMaintainerListener(); 



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
            virtual void OnInsertInstance(CObjectPtr & instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void OnRemoveInstance(CObjectPtr & instance); 



    };  //end class CMaintainerListener



} //end namespace atom



#endif
