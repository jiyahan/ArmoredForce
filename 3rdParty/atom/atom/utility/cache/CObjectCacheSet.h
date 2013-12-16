#ifndef COBJECTCACHESET_H
#define COBJECTCACHESET_H
//Begin section for file CObjectCacheSet.h
//TODO: Add definitions that you want preserved
//End section for file CObjectCacheSet.h
#include "CObjectCacheSetBind.h"
#include "../tool/CObjectPtr.h"
#include "../../pattern/factory/CInstanceFactory.h"
#include "../../pattern/life/CInstanceLife.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CObjectCacheSet
    {

        //Begin section for atom::CObjectCacheSet
        //TODO: Add attributes that you want preserved
        //End section for atom::CObjectCacheSet

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CObjectCacheSetBind objects[CONTAINER_QUEUE];




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CObjectCacheSet()
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CObjectCacheSet() 
            {
                //TODO Auto-generated method stub
                Release();
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CObjectPtr Inquire(U64 name)
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void ClearUp(U64 name)
            {
                //TODO Auto-generated method stub
                size_t offset = name % CONTAINER_QUEUE;
                CObjectCacheSetBind::
                    iterator it = objects[offset].find( name );
                if( it != objects[offset].end() ) {
                    CInstanceLife::GetInstance() -> Decrease( name );
                    objects[offset].erase( it );
                }
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Recycle() 
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Release()
            {
                //TODO Auto-generated method stub
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
