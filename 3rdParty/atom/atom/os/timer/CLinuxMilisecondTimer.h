#ifndef CLINUXMILISECONDTIMER_H
#define CLINUXMILISECONDTIMER_H
#include "../../Common.h"



namespace atom
{



    class CLinuxMilisecondTimer
    {


        private:


            #ifdef __linux
            timeval timestamp;
            #endif




        public:

            inline CLinuxMilisecondTimer()
            {
                #ifdef __linux
                timestamp.tv_sec  = 0;
                timestamp.tv_usec = 0;
                #endif
            }



            inline ~CLinuxMilisecondTimer()
            {
            }



            inline bool Record()
            {
                #ifdef __linux
                gettimeofday( &timestamp, NULL );
                #endif
                return true;
            }



            inline U64 GetElapsedTime()
            {
                U64 result = 0;
        
                #ifdef __linux
                timeval timevalue;
                gettimeofday( &timevalue, NULL );
        
                U64 start = static_cast<U64>( timestamp.tv_sec ) * 1000 + static_cast<U64>( timestamp.tv_usec ) / 1000;
                U64 end   = static_cast<U64>( timevalue.tv_sec ) * 1000 + static_cast<U64>( timevalue.tv_usec ) / 1000;
                if( end > start ) result = end - start;
                #endif

                return result;
            }



            inline U64 GetElapsedTimeAndRecord()
            {
                U64 result = 0;
        
                #ifdef __linux
                timeval timevalue;
                gettimeofday( &timevalue, NULL );
        
                U64 start = static_cast<U64>( timestamp.tv_sec ) * 1000 + static_cast<U64>( timestamp.tv_usec ) / 1000;
                U64 end   = static_cast<U64>( timevalue.tv_sec ) * 1000 + static_cast<U64>( timevalue.tv_usec ) / 1000;
                if( end > start ) result = end - start;
        
                timestamp = timevalue;
                #endif

                return result;
            }



            inline static U64 Now()
            {
                U64 result = 0;
        
                #ifdef __linux
                timeval timevalue;
                gettimeofday( &timevalue, NULL );
                result = static_cast<U64>( timevalue.tv_sec ) * 1000 + static_cast<U64>( timevalue.tv_usec ) / 1000;
                #endif

                return result;
            }



    };  //end class CLinuxMilisecondTimer


}//end namespace atom


#endif
