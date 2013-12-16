#ifndef CMAINTAINER_H
#define CMAINTAINER_H
//Begin section for file CMaintainer.h
//TODO: Add definitions that you want preserved
//End section for file CMaintainer.h
#include "../interface/IInterface.h"
#include "CMaintainerLife.h"
#include "CMaintainerSingletonBind.h"
#include "CMaintainerThread.h"
#include "CMaintainerListener.h"
#include "CMaintainerTimeline.h"
#include "../pattern/container/CInstanceContainer.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMaintainer : public IInterface, public CMaintainerSingletonBind
    {

        //Begin section for atom::CMaintainer
        //TODO: Add attributes that you want preserved
        //End section for atom::CMaintainer

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerThread thread;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceContainer container;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerListener listener;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerTimeline timeline;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerLife life;



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainer(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CMaintainer(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Attach(CObjectPtr & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Detach(CObjectPtr & value); 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Detach(U64 instance_name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Initiate(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool Shutdown(); 



    };  //end class CMaintainer



} //end namespace atom



#endif
