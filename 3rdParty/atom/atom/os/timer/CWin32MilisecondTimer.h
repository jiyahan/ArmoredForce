#ifndef CWIN32MILISECONDTIMER_H
#define CWIN32MILISECONDTIMER_H
#include "../../Common.h"



namespace atom
{



    class CWin32MilisecondTimer
    {


        private:


            U64 timestamp;




        public:

            inline CWin32MilisecondTimer() :
            timestamp(0)
            {
            }



            inline ~CWin32MilisecondTimer()
            {
            }


            
            inline bool Record()
            {
                #ifdef _WIN32
                timestamp = timeGetTime();
                return true;

                #else
                return false;
                #endif
            }



            inline U64 GetElapsedTime()
            {
                U64 result = 0;
        
                #ifdef _WIN32
                result = timeGetTime() - timestamp;
                #endif
        
                return result;
            }



            inline U64 GetElapsedTimeAndRecord()
            {
                U64 result = 0;
        
                #ifdef _WIN32
                U64 time  = timeGetTime();
                result    = time - timestamp;
                timestamp = time;
                #endif
        
                return result;
            }



            inline static U64 Now()
            {
                U64 result = 0;
        
                #ifdef _WIN32
                result = timeGetTime();
                #endif
        
                return result;
            }



    };  //end class CWin32MilisecondTimer


}//end namespace atom


#endif
