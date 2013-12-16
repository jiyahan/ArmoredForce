#ifndef TAGMEMORYTOTAL_H
#define TAGMEMORYTOTAL_H
//Begin section for file tagMemoryTotal.h
//TODO: Add definitions that you want preserved
//End section for file tagMemoryTotal.h
#include "../../Common.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    struct tagMemoryTotal
    {

        //Begin section for atom::tagMemoryTotal
        //TODO: Add attributes that you want preserved
        //End section for atom::tagMemoryTotal



        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 a_count;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 r_count;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 m_count;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagMemoryTotal(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~tagMemoryTotal(); 



    };  //end struct tagMemoryTotal


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemoryTotal::tagMemoryTotal() : 
a_count(0),r_count(0),m_count(0)
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemoryTotal::~tagMemoryTotal() 
{
    //TODO Auto-generated method stub
}

#endif
