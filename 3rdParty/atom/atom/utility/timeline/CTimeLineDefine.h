#ifndef CTIMELINEDEFINE_H
#define CTIMELINEDEFINE_H
#include "tagTimeLine.h"
#include "../stl/stl_extend.h"



namespace atom
{



    template <class T>
    class CTimeLineDefine
    {


        public:


            typedef std::set<tagTimeLine<T>, less<tagTimeLine<T> >, atom_allocator<tagTimeLine<T> > >  timeline_type ;



            typedef HASH_MAP_DEF(T, U64)  timedata_type ;



    };  //end class CTimeLineDefine



} //end namespace atom



#endif
