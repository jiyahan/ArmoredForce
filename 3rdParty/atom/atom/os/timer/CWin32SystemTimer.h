#ifndef CWIN32SYSTEMTIMER_H
#define CWIN32SYSTEMTIMER_H
//Begin section for file CWin32SystemTimer.h
//TODO: Add definitions that you want preserved
//End section for file CWin32SystemTimer.h
#include "../../Common.h"
#include "../../utility/stl/a_string.h"




namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32SystemTimer
    {

        //Begin section for atom::CWin32SystemTimer
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32SystemTimer

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            I64 record;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CWin32SystemTimer() : record(0)
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CWin32SystemTimer()
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Record()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value ); record = value;
                return true;

                #else

                return false;
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void SetRecord(I64 value)
            {
                //TODO Auto-generated method stub
                record = value;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline I64 GetRecord()
            {
                //TODO Auto-generated method stub
                return record;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline I64 GetElapsedTime()
            {
                //TODO Auto-generated method stub
                I64 result = 0;

                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value ); result = value - record;
                #endif

                return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline I64 GetElapsedTimeAndRecord()
            {
                //TODO Auto-generated method stub
                I64 result = 0;

                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value );
                result = value - record;
                record = value;
                #endif

                return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static I64 Now()
            {
                //TODO Auto-generated method stub
                I64 result = 0;

                #ifdef _WIN32
                __time64_t value = 0;
                _time64( &value ); result = value;
                #endif

                return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static void TimeToString(I64 time, a_string & string)
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static bool StringToTime(a_string & string, I64 & time)
            {
                //TODO Auto-generated method stub
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
