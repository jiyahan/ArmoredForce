#ifndef COBJECTCACHE_H
#define COBJECTCACHE_H
#include "CObjectCacheSet.h"
#include "../tool/CObjectPtr.h"



namespace atom
{



    class CObjectCache
    {


        private:

            static TLS_DECLARE CObjectCacheSet * cache;




        public:

            static void Initiate(); 



            static void Shutdown(); 



            inline static CObjectPtr Inquire(U64 name)
            {
                if( cache )
                    return cache -> Inquire( name );
                else
                    return CInstanceFactory::GetInstance() -> Inquire( name );
            }



            inline static void ClearUp(U64 name)
            {
                if( cache ) cache -> ClearUp( name );
            }



            static void Recover(); 



    };  //end class CObjectCache



} //end namespace atom



#endif
