#ifndef TAGTIMELINE_H
#define TAGTIMELINE_H
#include "../../Common.h"
#include "../stl/allocator.h"


namespace atom
{



    template <class T>
    struct tagTimeLine
    {


        public:


            typedef std::vector<T, atom_allocator<T> >  CTimeDataArray ;



        public:


            U64 time;



            CTimeDataArray data;




            inline tagTimeLine(): 
            time(0)
            {
                data.reserve( 64 );
            }


            inline tagTimeLine(const tagTimeLine & value): 
            time(0)
            {
                data.reserve( 64 );
                *this = value;
            }


            inline tagTimeLine(U64 v1, const T & v2): 
            time(v1)
            {
                data.reserve( 64 ); data.push_back( v2 );
            }


            inline ~tagTimeLine()
            {
            }


            inline bool  operator ==(const tagTimeLine & value) const
            {
                return time == value.time;
            }


            inline tagTimeLine & operator =(const tagTimeLine & value) 
            {
                time = value.time;
                data = value.data;
                return( *this );
            }


            inline bool  operator >(const tagTimeLine & value) const 
            {
                return time > value.time;
            }


            inline bool  operator <(const tagTimeLine & value) const 
            {
                return time < value.time;
            }

    };  //end struct tagTimeLine



} //end namespace atom



#endif
