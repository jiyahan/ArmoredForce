#ifndef CAPPLEMILISECONDTIMER_H
#define CAPPLEMILISECONDTIMER_H
#include "../../Common.h"



namespace atom
{



    class CAppleMilisecondTimer
    {


        private:


            #ifdef __APPLE__
            timeval timestamp;
            #endif




        public:

            inline CAppleMilisecondTimer()
            {
				#ifdef __APPLE__
                timestamp.tv_sec  = 0;
                timestamp.tv_usec = 0;
                #endif
            }



            inline ~CAppleMilisecondTimer()
            {
            }



            inline bool Record()
            {
				#ifdef __APPLE__
                gettimeofday( &timestamp, NULL );
                #endif
                return true;
            }



            inline U64 GetElapsedTime()
            {
                U64 result = 0;
        
				#ifdef __APPLE__
                timeval timevalue;
                gettimeofday( & timevalue, NULL );
        
                U64 start = static_cast<U64>( timestamp.tv_sec ) * 1000 + static_cast<U64>( timestamp.tv_usec ) / 1000;
                U64 end   = static_cast<U64>( timevalue.tv_sec ) * 1000 + static_cast<U64>( timevalue.tv_usec ) / 1000;
                if( end > start ) result = end - start;
                #endif

                return result;
            }



            inline U64 GetElapsedTimeAndRecord()
            {
                U64 result = 0;
        
				#ifdef __APPLE__
                timeval timevalue;
                gettimeofday( & timevalue, NULL );
        
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
        
				#ifdef __APPLE__
                timeval time;
                gettimeofday( & time, NULL );
                result = static_cast<U64>( time.tv_sec ) * 1000 + static_cast<U64>( time.tv_usec ) / 1000;
                #endif

                return result;
            }



    };  //end class CAppleMilisecondTimer


}//end namespace atom


#endif
