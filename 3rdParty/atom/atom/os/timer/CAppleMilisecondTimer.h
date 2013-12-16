#ifndef CAPPLEMILISECONDTIMER_H
#define CAPPLEMILISECONDTIMER_H
//Begin section for file CAppleMilisecondTimer.h
//TODO: Add definitions that you want preserved
//End section for file CAppleMilisecondTimer.h
#include "../../Common.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CAppleMilisecondTimer
    {

        //Begin section for atom::CAppleMilisecondTimer
        //TODO: Add attributes that you want preserved
        //End section for atom::CAppleMilisecondTimer

        private:


            #ifdef __APPLE__
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            timeval timestamp;
            #endif




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CAppleMilisecondTimer()
            {
                //TODO Auto-generated method stub
				#ifdef __APPLE__
                timestamp.tv_sec  = 0;
                timestamp.tv_usec = 0;
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CAppleMilisecondTimer()
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Record()
            {
                //TODO Auto-generated method stub
				#ifdef __APPLE__
                gettimeofday( &timestamp, NULL );
                #endif
                return true;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline U64 GetElapsedTime()
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline U64 GetElapsedTimeAndRecord()
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static U64 Now()
            {
                //TODO Auto-generated method stub
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
