#ifndef CTIMELINEDEFINE_H
#define CTIMELINEDEFINE_H
//Begin section for file CTimeLineDefine.h
//TODO: Add definitions that you want preserved
//End section for file CTimeLineDefine.h
#include "tagTimeLine.h"
#include "../stl/stl_extend.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    class CTimeLineDefine
    {

        //Begin section for atom::CTimeLineDefine
        //TODO: Add attributes that you want preserved
        //End section for atom::CTimeLineDefine

        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typedef std::set<tagTimeLine<T>, less<tagTimeLine<T> >, atom_allocator<tagTimeLine<T> > >  timeline_type ;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typedef HASH_MAP_DEF(T, U64)  timedata_type ;



    };  //end class CTimeLineDefine



} //end namespace atom



#endif
