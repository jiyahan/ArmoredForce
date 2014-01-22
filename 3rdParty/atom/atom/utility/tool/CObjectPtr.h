#ifndef COBJECTPTR_H
#define COBJECTPTR_H
#include "../../interface/IReferencedObject.h"



namespace atom
{



    class CObjectPtr
    {


        private:


            IReferencedObject * object;




        public:

            inline CObjectPtr(); 



            inline CObjectPtr(IReferencedObject * objectable); 



            inline CObjectPtr(const CObjectPtr & value); 



            inline virtual ~CObjectPtr(); 



            inline CObjectPtr & operator =(const CObjectPtr & value); 



            inline operator IReferencedObject *(); 



            inline IReferencedObject * operator ->(); 



    };  //end class CObjectPtr



} //end namespace atom



atom::CObjectPtr::CObjectPtr() : 
object(NULL)
{
}

atom::CObjectPtr::CObjectPtr(IReferencedObject * objectable) : 
object(NULL)
{
    if( objectable &&
        objectable -> IncRef() ) {
        object = objectable;
    }
}

atom::CObjectPtr::CObjectPtr(const CObjectPtr & value) : 
object(NULL)
{
    if( value.object &&
        value.object -> IncRef() ) {
        object = value.object;
    }
}

atom::CObjectPtr::~CObjectPtr() 
{
    SAFE_DECREF( object );
}

atom::CObjectPtr & atom::CObjectPtr::operator =(const CObjectPtr & value) 
{
    SAFE_DECREF( object );
    if( value.object && 
        value.object -> IncRef() ) {
        object = value.object;
    }
    return( *this );
}

atom::CObjectPtr::operator atom::IReferencedObject* () 
{
    return object;
}

atom::IReferencedObject * atom::CObjectPtr::operator -> () 
{
    return object;
}

#endif
