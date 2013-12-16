#ifndef COBJECTPTR_H
#define COBJECTPTR_H
//Begin section for file CObjectPtr.h
//TODO: Add definitions that you want preserved
//End section for file CObjectPtr.h
#include "../../interface/IReferencedObject.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CObjectPtr
    {

        //Begin section for atom::CObjectPtr
        //TODO: Add attributes that you want preserved
        //End section for atom::CObjectPtr

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IReferencedObject * object;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CObjectPtr(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CObjectPtr(IReferencedObject * objectable); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CObjectPtr(const CObjectPtr & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CObjectPtr(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CObjectPtr & operator =(const CObjectPtr & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline operator IReferencedObject *(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline IReferencedObject * operator ->(); 



    };  //end class CObjectPtr



} //end namespace atom



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr::CObjectPtr() : 
object(NULL)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr::CObjectPtr(IReferencedObject * objectable) : 
object(NULL)
{
    //TODO Auto-generated method stub
    if( objectable &&
        objectable -> IncRef() ) {
        object = objectable;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr::CObjectPtr(const CObjectPtr & value) : 
object(NULL)
{
    //TODO Auto-generated method stub
    if( value.object &&
        value.object -> IncRef() ) {
        object = value.object;
    }
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr::~CObjectPtr() 
{
    //TODO Auto-generated method stub
    SAFE_DECREF( object );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr & atom::CObjectPtr::operator =(const CObjectPtr & value) 
{
    //TODO Auto-generated method stub
    SAFE_DECREF( object );
    if( value.object && 
        value.object -> IncRef() ) {
        object = value.object;
    }
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr::operator atom::IReferencedObject* () 
{
    //TODO Auto-generated method stub
    return object;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::IReferencedObject * atom::CObjectPtr::operator -> () 
{
    //TODO Auto-generated method stub
    return object;
}

#endif
