#ifndef CCRITICALSECTIONSCOPE_H
#define CCRITICALSECTIONSCOPE_H
//Begin section for file CCriticalSectionScope.h
//TODO: Add definitions that you want preserved
//End section for file CCriticalSectionScope.h
#include "../../os/thread/CCriticalSection.h"



namespace atom
{



    class CCriticalSectionScope
    {

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection & section;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CCriticalSectionScope & operator =(const CCriticalSectionScope & value); 



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CCriticalSectionScope(CCriticalSection & section); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CCriticalSectionScope(); 



    };  //end class CCriticalSectionScope


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CCriticalSectionScope::CCriticalSectionScope(CCriticalSection & value) :
section(value)
{
    //TODO Auto-generated method stub
    section.Enter();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CCriticalSectionScope::~CCriticalSectionScope() 
{
    //TODO Auto-generated method stub
    section.Leave();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CCriticalSectionScope & atom::CCriticalSectionScope::operator =(const CCriticalSectionScope & value) 
{
    //TODO Auto-generated method stub
    UNREFERENCED_PARAMETER( value );
    return( *this );
}

#endif
