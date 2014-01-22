#ifndef CCRITICALSECTIONSCOPE_H
#define CCRITICALSECTIONSCOPE_H
#include "../../os/thread/CCriticalSection.h"



namespace atom
{



    class CCriticalSectionScope
    {

        private:


            CCriticalSection & section;



            inline CCriticalSectionScope & operator =(const CCriticalSectionScope & value); 



        public:

            inline CCriticalSectionScope(CCriticalSection & section); 



            inline virtual ~CCriticalSectionScope(); 



    };  //end class CCriticalSectionScope


}//end namespace atom


atom::CCriticalSectionScope::CCriticalSectionScope(CCriticalSection & value) :
section(value)
{
    section.Enter();
}

atom::CCriticalSectionScope::~CCriticalSectionScope() 
{
    section.Leave();
}

atom::CCriticalSectionScope & atom::CCriticalSectionScope::operator =(const CCriticalSectionScope & value) 
{
    UNREFERENCED_PARAMETER( value );
    return( *this );
}

#endif
