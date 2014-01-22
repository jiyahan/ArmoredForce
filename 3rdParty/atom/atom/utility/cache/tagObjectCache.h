#ifndef TAGOBJECTCACHE_H
#define TAGOBJECTCACHE_H
#include "../tool/CObjectPtr.h"



namespace atom
{



    struct tagObjectCache
    {




        public:


            CObjectPtr object;



            U64 lasted;



            inline tagObjectCache(const CObjectPtr & value) :
            object(value),lasted(15)
            {
            }



            inline tagObjectCache(const tagObjectCache & value) :
            object(value.object),lasted(value.lasted)
            {
            }



            inline ~tagObjectCache()
            {
            }



            inline tagObjectCache & operator =(CObjectPtr & value)
            {
                object = value;
                lasted = 15; // 保证对象进入缓存之后，有4次衰减时间；
                return( * this );
            }



            inline tagObjectCache & operator =(const tagObjectCache & value)
            {
                object = value.object;
                lasted = value.lasted;
                return( * this );
            }



    };  //end struct tagObjectCache



} //end namespace atom



#endif
