#ifndef CWIN32THREAD_H
#define CWIN32THREAD_H
//Begin section for file CWin32Thread.h
//TODO: Add definitions that you want preserved
//End section for file CWin32Thread.h
#include "../../Common.h"
#include "CCriticalSection.h"
#include "../../enumeration/THREAD_PRIORITY.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CWin32Thread
    {

        //Begin section for atom::CWin32Thread
        //TODO: Add attributes that you want preserved
        //End section for atom::CWin32Thread

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            std::string thread;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void * handle;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection region;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            explicit CWin32Thread(const char * name); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CWin32Thread(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            const char * GetName(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Begin(U08 priority = TP_NORMAL); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool Close(U64 timeout); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnThreadBegin(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool OnThreadClose(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U32 Run(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static void Sleep(U64 milisecond); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static U64 GetCurrentThreadID(); 



    };  //end class CWin32Thread


}//end namespace atom


#endif
