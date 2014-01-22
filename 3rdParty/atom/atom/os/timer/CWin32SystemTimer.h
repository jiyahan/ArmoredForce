#ifndef CWIN32SYSTEMTIMER_H
#define CWIN32SYSTEMTIMER_H
#include "../../Common.h"
#include "../../utility/stl/a_string.h"




namespace atom
{



    class CWin32SystemTimer
    {


        private:


            I64 record;




        public:

            inline CWin32SystemTimer() : record(0)
            {
            }



            inline ~CWin32SystemTimer()
            {
            }



            inline bool Record()
            {
                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value ); record = value;
                return true;

                #else

                return false;
                #endif
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

                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value ); result = value - record;
                #endif

                return result;
            }



            inline I64 GetElapsedTimeAndRecord()
            {
                I64 result = 0;

                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value );
                result = value - record;
                record = value;
                #endif

                return result;
            }



            inline static I64 Now()
            {
                I64 result = 0;

                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value ); result = value;
                #endif

                return result;
            }



            inline static void TimeToString(I64 time, a_string & string)
            {
                #ifdef _WIN32
                tm desc;
                memset( & desc, 0, sizeof(desc) );

                __time64_t value( time );
                _localtime64_s( & desc, & value );

                char buffer[128];
                sprintf( buffer, "%04d-%02d-%02d %02d:%02d:%02d", desc.tm_year + 1900, 
                    desc.tm_mon + 1, desc.tm_mday, desc.tm_hour, desc.tm_min, desc.tm_sec );
                string = buffer;
                #else

                UNREFERENCED_PARAMETER( string );
                UNREFERENCED_PARAMETER( time   );
                #endif
            }



            inline static bool StringToTime(a_string & string, I64 & time)
            {
                bool result = false;

                #ifdef _WIN32
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
                            result = true; time = _mktime64( &desc );
                        }
                    }
                }
                #else

                UNREFERENCED_PARAMETER( string );
                UNREFERENCED_PARAMETER( time   );
                #endif

                return result;
            }



    };  //end class CWin32SystemTimer


}//end namespace atom


#endif
