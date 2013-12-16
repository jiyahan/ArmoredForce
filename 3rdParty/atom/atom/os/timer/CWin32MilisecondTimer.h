#ifndef CWIN32MILISECONDTIMER_H
#define CWIN32MILISECONDTIMER_H
//Begin section for file CWin32MilisecondTimer.h
//TODO: Add definitions that you want preserved
//End section for file CWin32MilisecondTimer.h
#include "../../Common.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32MilisecondTimer
    {

        //Begin section for atom::CWin32MilisecondTimer
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32MilisecondTimer

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64 timestamp;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CWin32MilisecondTimer() :
            timestamp(0)
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~CWin32MilisecondTimer()
            {
                //TODO Auto-generated method stub
            }


            
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool Record()
            {
                //TODO Auto-generated method stub
                #ifdef _WIN32
                timestamp = timeGetTime();
                return true;

                #else
                return false;
                #endif
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline U64 GetElapsedTime()
            {
                //TODO Auto-generated method stub
                U64 result = 0;
        
                #ifdef _WIN32
                result = timeGetTime() - timestamp;
                #endif
        
                return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline U64 GetElapsedTimeAndRecord()
            {
                //TODO Auto-generated method stub
                U64 result = 0;
        
                #ifdef _WIN32
                U64 time  = timeGetTime();
                result    = time - timestamp;
                timestamp = time;
                #endif
        
                return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static U64 Now()
            {
                //TODO Auto-generated method stub
                U64 result = 0;
        
                #ifdef _WIN32
                result = timeGetTime();
                #endif
        
                return result;
            }



    };  //end class CWin32MilisecondTimer


}//end namespace atom


#endif
