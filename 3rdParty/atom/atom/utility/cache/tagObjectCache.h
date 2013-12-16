#ifndef TAGOBJECTCACHE_H
#define TAGOBJECTCACHE_H
//Begin section for file tagObjectCache.h
//TODO: Add definitions that you want preserved
//End section for file tagObjectCache.h
#include "../tool/CObjectPtr.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    struct tagObjectCache
    {

        //Begin section for atom::tagObjectCache
        //TODO: Add attributes that you want preserved
        //End section for atom::tagObjectCache



        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CObjectPtr object;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 lasted;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagObjectCache(const CObjectPtr & value) :
            object(value),lasted(15)
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagObjectCache(const tagObjectCache & value) :
            object(value.object),lasted(value.lasted)
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~tagObjectCache()
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagObjectCache & operator =(CObjectPtr & value)
            {
                //TODO Auto-generated method stub
                object = value;
                lasted = 15; // 保证对象进入缓存之后，有4次衰减时间；
                return( * this );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagObjectCache & operator =(const tagObjectCache & value)
            {
                //TODO Auto-generated method stub
                object = value.object;
                lasted = value.lasted;
                return( * this );
            }



    };  //end struct tagObjectCache



} //end namespace atom



#endif
