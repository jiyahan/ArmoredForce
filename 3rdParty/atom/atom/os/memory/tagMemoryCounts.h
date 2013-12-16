#ifndef TAGMEMORYCOUNTS_H
#define TAGMEMORYCOUNTS_H
//Begin section for file tagMemoryCounts.h
//TODO: Add definitions that you want preserved
//End section for file tagMemoryCounts.h
#include "tagMemoryCount.h"



namespace atom
{



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     struct tagMemoryCounts
     {

         //Begin section for atom::tagMemoryCounts
         //TODO: Add attributes that you want preserved
         //End section for atom::tagMemoryCounts



         public:


             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             tagMemoryCount stages[MEMORY_FRAGMENT_QUEUE];



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline tagMemoryCounts(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             inline ~tagMemoryCounts(); 



     };  //end struct tagMemoryCounts


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemoryCounts::tagMemoryCounts() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagMemoryCounts::~tagMemoryCounts() 
{
    //TODO Auto-generated method stub
}

#endif
