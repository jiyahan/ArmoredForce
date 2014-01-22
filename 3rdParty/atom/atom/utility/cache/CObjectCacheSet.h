#ifndef COBJECTCACHESET_H
#define COBJECTCACHESET_H
#include "CObjectCacheSetBind.h"
#include "../tool/CObjectPtr.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../pattern/life/CInstanceLife.h"



namespace atom
{



    class CObjectCacheSet
    {


        private:


            CObjectCacheSetBind objects[CONTAINER_QUEUE];




        public:

            inline CObjectCacheSet()
            {
            }



            inline ~CObjectCacheSet() 
            {
                Release();
            }



            inline CObjectPtr Inquire(U64 name)
            {
                size_t offset = name % CONTAINER_QUEUE;

                // 先确认是否存在于队列内；
                CObjectCacheSetBind::iterator it = objects[offset].find( name );
                if( it != objects[offset].end() )
                {
                    if( it -> second.object ) { ++ 
                        it -> second.lasted;
                        return it -> second.object;
                    }
                }

                // 如果不存在于内，则通过远程工厂查找；
                CObjectPtr result = CInstanceFactory::GetInstance() -> Inquire( name );
                if( result )
                {
                    pair<CObjectCacheSetBind::iterator, 
                        bool> retval = objects[offset].insert( make_pair(name, result) );
                    if( retval.second ) {
                        CInstanceLife::GetInstance() -> Increase( name );
                    }
                }
                return result;
            }



            inline void ClearUp(U64 name)
            {
                size_t offset = name % CONTAINER_QUEUE;
                CObjectCacheSetBind::
                    iterator it = objects[offset].find( name );
                if( it != objects[offset].end() ) {
                    CInstanceLife::GetInstance() -> Decrease( name );
                    objects[offset].erase( it );
                }
            }



            inline void Recycle() 
            {
                for( size_t i = 0; i < CONTAINER_QUEUE; ++ i )
                {
                    // 如果队列为空，则跳过；
                    if( objects[i].empty() ) continue;

                    for( CObjectCacheSetBind::iterator 
                        it = objects[i].begin(); it != objects[i].end(); )
                    {
                        // 首先让访问计数除2；
                        it -> second.lasted = it -> second.lasted >> 1;

                        // 如果访问计数依然有效，则继续；
                        if( it -> second.lasted ) { it ++; continue; }

                        // 如果访问计数无效，则移除对象；
                        CInstanceLife::GetInstance() -> Decrease( it -> first );
                        SAFE_ERASE( objects[i], it );
                    }
                }
            }



            inline void Release()
            {
                for( size_t i = 0; i < CONTAINER_QUEUE; ++ i )
                {
                    for( CObjectCacheSetBind::iterator
                        it = objects[i].begin(); it != objects[i].end(); ++ it ) {
                        CInstanceLife::GetInstance() -> Decrease( it -> first );
                    }
                    objects[i].clear();
                }
            }



    };  //end class CObjectCacheSet



} //end namespace atom



#endif
