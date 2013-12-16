#ifndef CWIN32CRITICALSECTION_H
#define CWIN32CRITICALSECTION_H
//Begin section for file CWin32CriticalSection.h
//TODO: Add definitions that you want preserved
//End section for file CWin32CriticalSection.h

#include "../../Common.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32CriticalSection
    {

        //Begin section for atom::CWin32CriticalSection
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32CriticalSection



        private:
        #ifdef _WIN32
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CRITICAL_SECTION section;
        #endif



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CWin32CriticalSection()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                InitializeCriticalSectionAndSpinCount( & section, 4096 );
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CWin32CriticalSection()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                DeleteCriticalSection( & section );
                #endif
            } 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Enter()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                EnterCriticalSection( & section );
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool TryEnter()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                return( TryEnterCriticalSection( & section ) == TRUE );
                #else
                return false;
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Leave()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                LeaveCriticalSection( & section );
                #endif
            }



    };  //end class CWin32CriticalSection


}//end namespace atom


#endif
