#ifndef COBJECTCACHE_H
#define COBJECTCACHE_H
//Begin section for file CObjectCache.h
//TODO: Add definitions that you want preserved
//End section for file CObjectCache.h
#include "CObjectCacheSet.h"
#include "../tool/CObjectPtr.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CObjectCache
    {

        //Begin section for atom::CObjectCache
        //TODO: Add attributes that you want preserved
        //End section for atom::CObjectCache

        private:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static TLS_DECLARE CObjectCacheSet * cache;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Initiate(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Shutdown(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static CObjectPtr Inquire(U64 name)
            {
                //TODO Auto-generated method stub
                if( cache )
                    return cache -> Inquire( name );
                else
                    return CInstanceFactory::GetInstance() -> Inquire( name );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static void ClearUp(U64 name)
            {
                //TODO Auto-generated method stub
                if( cache ) cache -> ClearUp( name );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Recover(); 



    };  //end class CObjectCache



} //end namespace atom



#endif
