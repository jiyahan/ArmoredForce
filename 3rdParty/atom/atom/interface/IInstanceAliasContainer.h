#ifndef IINSTANCEALIASCONTAINER_H
#define IINSTANCEALIASCONTAINER_H
//Begin section for file IInstanceAliasContainer.h
//TODO: Add definitions that you want preserved
//End section for file IInstanceAliasContainer.h
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"
#include "../utility/stl/allocator.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    class IInstanceAliasContainer : public IEmbedInterface
    {

        //Begin section for atom::IInstanceAliasContainer
        //TODO: Add attributes that you want preserved
        //End section for atom::IInstanceAliasContainer



        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool  Insert(const T & alias, CObjectPtr & instance) = 0;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual CObjectPtr  Obtain(const T & alias) = 0;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void  Obtain(std::vector<T, atom_allocator<T> > & out) = 0;

        

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool  Inside(const T & alias) = 0;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64  Amount() = 0;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool  Remove(const T & alias) = 0;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void  RemoveAll() = 0;



    };  //end class IInstanceAliasContainer



} //end namespace atom



#endif
