#ifndef CRANDOM_H
#define CRANDOM_H
//Begin section for file CRandom.h
//TODO: Add definitions that you want preserved
//End section for file CRandom.h
#include "../../../Common.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CRandom
    {

        //Begin section for atom::CRandom
        //TODO: Add attributes that you want preserved
        //End section for atom::CRandom



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Initiate(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static int Random(); 



    };  //end class CRandom


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
int atom::CRandom::Random() 
{
    //TODO Auto-generated method stub
    return( rand() / 2 + rand() / 2 );
}

#endif
