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

                // ��ȷ���Ƿ�����ڶ����ڣ�
                CObjectCacheSetBind::iterator it = objects[offset].find( name );
                if( it != objects[offset].end() )
                {
                    if( it -> second.object ) { ++ 
                        it -> second.lasted;
                        return it -> second.object;
                    }
                }

                // ������������ڣ���ͨ��Զ�̹������ң�
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
                    // �������Ϊ�գ���������
                    if( objects[i].empty() ) continue;

                    for( CObjectCacheSetBind::iterator 
                        it = objects[i].begin(); it != objects[i].end(); )
                    {
                        // �����÷��ʼ�����2��
                        it -> second.lasted = it -> second.lasted >> 1;

                        // ������ʼ�����Ȼ��Ч���������
                        if( it -> second.lasted ) { it ++; continue; }

                        // ������ʼ�����Ч�����Ƴ�����
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
