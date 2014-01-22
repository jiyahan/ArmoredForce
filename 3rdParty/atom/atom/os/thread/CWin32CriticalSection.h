#ifndef CWIN32CRITICALSECTION_H
#define CWIN32CRITICALSECTION_H

#include "../../Common.h"


namespace atom
{



    class CWin32CriticalSection
    {




        private:
        #ifdef _WIN32
            CRITICAL_SECTION section;
        #endif



        public:

            inline CWin32CriticalSection()
            {
                #ifdef _WIN32
                InitializeCriticalSectionAndSpinCount( & section, 4096 );
                #endif
            }



            inline ~CWin32CriticalSection()
            {
                #ifdef _WIN32
                DeleteCriticalSection( & section );
                #endif
            } 



            inline void Enter()
            {
                #ifdef _WIN32
                EnterCriticalSection( & section );
                #endif
            }



            inline bool TryEnter()
            {
                #ifdef _WIN32
                return( TryEnterCriticalSection( & section ) == TRUE );
                #else
                return false;
                #endif
            }



            inline void Leave()
            {
                #ifdef _WIN32
                LeaveCriticalSection( & section );
                #endif
            }



    };  //end class CWin32CriticalSection


}//end namespace atom


#endif
