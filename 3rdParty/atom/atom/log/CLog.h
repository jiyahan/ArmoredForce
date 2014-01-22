#ifndef CLOG_H
#define CLOG_H
#include "../interface/IInterface.h"
#include "CLogExporter.h"
#include "CLogArchive.h"
#include "../enumeration/END_DEBUG.h"
#include "../enumeration/END_ALARM.h"
#include "../enumeration/END_ERROR.h"
#include "../enumeration/LINE_END.h"



namespace atom
{



    class CLog : public IInterface
    {


        private:


            CLogExporter exporter;



            CLogArchive archive;




        public:

            CLog(); 



            virtual ~CLog(); 



            virtual IInterface * QueryInterface(U32 iid); 



            template <class T>
            inline CLog & operator <<(T & value)
            {
                exporter.Bind( value );
                return( *this );
            }



            template <class T>
            inline CLog & operator <<(const T & value)
            {
                exporter.Bind( value );
                return( *this );
            }


            CLog & operator <<(const char * message); 



            CLog & operator <<(LINE_END flag); 



            void operator <<(END_DEBUG flag); 



            void operator <<(END_ALARM flag); 



            void operator <<(END_ERROR flag); 



    };  //end class CLog



} //end namespace atom



#endif
