#ifndef CLOG_H
#define CLOG_H
//Begin section for file CLog.h
//TODO: Add definitions that you want preserved
//End section for file CLog.h
#include "../interface/IInterface.h"
#include "CLogExporter.h"
#include "CLogArchive.h"
#include "../enumeration/END_DEBUG.h"
#include "../enumeration/END_ALARM.h"
#include "../enumeration/END_ERROR.h"
#include "../enumeration/LINE_END.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CLog : public IInterface
    {

        //Begin section for atom::CLog
        //TODO: Add attributes that you want preserved
        //End section for atom::CLog

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLogExporter exporter;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLogArchive archive;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLog(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CLog(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            inline CLog & operator <<(T & value)
            {
                //TODO Auto-generated method stub
                exporter.Bind( value );
                return( *this );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            inline CLog & operator <<(const T & value)
            {
                //TODO Auto-generated method stub
                exporter.Bind( value );
                return( *this );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLog & operator <<(const char * message); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLog & operator <<(LINE_END flag); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void operator <<(END_DEBUG flag); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void operator <<(END_ALARM flag); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void operator <<(END_ERROR flag); 



    };  //end class CLog



} //end namespace atom



#endif
