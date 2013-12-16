#ifndef TAGTIMELINE_H
#define TAGTIMELINE_H
//Begin section for file tagTimeLine.h
//TODO: Add definitions that you want preserved
//End section for file tagTimeLine.h
#include "../../Common.h"
#include "../stl/allocator.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    struct tagTimeLine
    {

        //Begin section for atom::tagTimeLine
        //TODO: Add attributes that you want preserved
        //End section for atom::tagTimeLine

        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typedef std::vector<T, atom_allocator<T> >  CTimeDataArray ;



        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 time;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CTimeDataArray data;




            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagTimeLine(): 
            time(0)
            {
                //TODO Auto-generated method stub
                data.reserve( 64 );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagTimeLine(const tagTimeLine & value): 
            time(0)
            {
                //TODO Auto-generated method stub
                data.reserve( 64 );
                *this = value;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagTimeLine(U64 v1, const T & v2): 
            time(v1)
            {
                //TODO Auto-generated method stub
                data.reserve( 64 ); data.push_back( v2 );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~tagTimeLine()
            {
                    //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  operator ==(const tagTimeLine & value) const
            {
                //TODO Auto-generated method stub
                return time == value.time;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagTimeLine & operator =(const tagTimeLine & value) 
            {
                //TODO Auto-generated method stub
                time = value.time;
                data = value.data;
                return( *this );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  operator >(const tagTimeLine & value) const 
            {
                //TODO Auto-generated method stub
                return time > value.time;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  operator <(const tagTimeLine & value) const 
            {
                //TODO Auto-generated method stub
                return time < value.time;
            }

    };  //end struct tagTimeLine



} //end namespace atom



#endif
