#ifndef CLINUXSYSTEMTIMER_H
#define CLINUXSYSTEMTIMER_H
#include "../../Common.h"
#include "../../utility/stl/a_string.h"




namespace atom
{



    class CLinuxSystemTimer
    {


        private:


            I64 record;




        public:

            inline CLinuxSystemTimer() : record(0)
            {
            } 



            inline ~CLinuxSystemTimer()
            {
            } 



            inline bool Record()
            {
                bool result = false;

                #ifdef __linux
                time_t value; time( & value ); 
                record = value; result = true;
                #endif

                return result;
            }



            inline void SetRecord(I64 value)
            {
                record = value;
            }



            inline I64 GetRecord()
            {
                return record;
            }



            inline I64 GetElapsedTime()
            {
                I64 result = 0;

                #ifdef __linux
                time_t value; 
                time( & value ); result = value - record;
                #endif

                return result;
            }



            inline I64 GetElapsedTimeAndRecord()
            {
                I64 result = 0;

                #ifdef __linux
                time_t value; 
                time( & value ); 
                result = value - record;
                record = value;
                #endif

                return result;
            }



            inline static I64 Now()
            {
                I64 result = 0;

                #ifdef __linux
                time_t value;
                time( & value ); result = value;
                #endif

                return result;
            }



            inline static void TimeToString(I64 tv, a_string & string)
            {
                #ifdef __linux

                tm desc; 
                memset( & desc, 0, sizeof(desc) );
                
                time_t time = tv;
                localtime_r( & time, & desc );

                char buffer[128];
                sprintf( buffer, "%04d-%02d-%02d %02d:%02d:%02d", 
                    desc.tm_year + 1900, 
                    desc.tm_mon  + 1, 
                    desc.tm_mday, desc.tm_hour, 
                    desc.tm_min,  desc.tm_sec );

                string = buffer;

                #else

                UNREFERENCED_PARAMETER( string );
                UNREFERENCED_PARAMETER( tv     );

                #endif
            }



            inline static bool StringToTime(a_string & string, I64 & time)
            {
                bool result = false;

                #ifdef __linux

                if( string.empty() == false )
                {
                    a_string::size_type offset = 0;
                    a_string::size_type pos    = 0;
            
                    // 解析字符串
                    pos             = string.find( '-', offset );
                    a_string year   = string.substr( offset, pos );
                    offset          = pos + 1;
            
                    pos             = string.find( '-', offset );
                    a_string month  = string.substr( offset, pos );
                    offset          = pos + 1;
            
                    pos             = string.find( ' ', offset );
                    a_string day    = string.substr( offset, pos );
                    offset          = pos + 1;
            
                    pos             = string.find( ':', offset );
                    a_string hour   = string.substr( offset, pos );
                    offset          = pos + 1;
            
                    pos             = string.find( ':', offset );
                    a_string min    = string.substr( offset, pos );
                    offset          = pos + 1;

                    a_string sec    = string.substr( offset, string.length() );
            
                    // 填充数据结构
                    if( year.empty() == false && month.empty() == false &&
                        day .empty() == false && hour .empty() == false &&
                        min .empty() == false && sec  .empty() == false )
                    {
                        tm desc;
                        memset( & desc, 0, sizeof(desc) );

                        desc.tm_year = atoi( year. c_str() ) - 1900;
                        desc.tm_mon  = atoi( month.c_str() ) - 1;
                        desc.tm_mday = atoi( day.  c_str() );
                        desc.tm_hour = atoi( hour. c_str() );
                        desc.tm_min  = atoi( min.  c_str() );
                        desc.tm_sec  = atoi( sec.  c_str() );
                
                        // 判断参数的有效性，主要是月份，日期，小时，分以及秒的有效区间；
                        if( desc.tm_mon  >= 0 && desc.tm_mon  <  12   &&
                            desc.tm_mday >= 1 && desc.tm_mday <= 31   &&
                            desc.tm_hour >= 0 && desc.tm_hour <  24   &&
                            desc.tm_min  >= 0 && desc.tm_min  <  60   &&
                            desc.tm_sec  >= 0 && desc.tm_sec  <  60 )
                        {
                            result = true; time = mktime( & desc );
                        }
                    }
                }
                
                #else

                UNREFERENCED_PARAMETER( string );
                UNREFERENCED_PARAMETER( time   );

                #endif

                return result;
            }



    };  //end class CLinuxSystemTimer


}//end namespace atom


#endif
