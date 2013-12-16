#ifndef CMESSAGEALLOCATOR_H
#define CMESSAGEALLOCATOR_H
//Begin section for file CMessageAllocator.h
//TODO: Add definitions that you want preserved
//End section for file CMessageAllocator.h
#include "CMessageAllocatorSingletonBind.h"
#include "CMessageAllocatorBind.h"



namespace electron
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMessageAllocator : public CMessageAllocatorSingletonBind, public CMessageAllocatorBind
    {

        //Begin section for electron::CMessageAllocator
        //TODO: Add attributes that you want preserved
        //End section for electron::CMessageAllocator

        public:



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void  Released(CMessage * object)
            {
                //TODO Auto-generated method stub
                if( object )
                {
                    object -> Shutdown();
                    CMessageAllocatorBind::Released( object );
                }
            }



    };  //end class CMessageAllocator



} //end namespace electron



#endif
