#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "../Common.h"
#include "CMessageEntry.h"
#include "CMessageLife.h"
#include "../enumeration/MESSAGE_ID.h"



namespace electron
{



    class CMessage : public IInterface
    {


        private:


            CImportableWrapper importable;



            CExportableWrapper exportable;



            CStream stream;



            CMessageEntry entry;



            CMessageLife life;




        public:

            explicit CMessage(U16 command = MID_UNKNOW); 



            virtual ~CMessage(); 



            bool Initiate(); 



            bool Shutdown(); 



            U16 GetCommandID(); 



            void SetConnector(U64 value); 



            U64 GetConnector(); 



            void Write(I08 value); 



            void Write(I16 value); 



            void Write(I32 value); 



            void Write(I64 value); 



            void Write(U08 value); 



            void Write(U16 value); 



            void Write(U32 value); 



            void Write(U64 value); 



            void Write(float value); 



            void Write(double value); 



            void Write(const char * value); 



            void Write(const wchar_t * value); 



            void Write(const void * bytes, U64 length); 



            I08 ReadI08(); 



            I16 ReadI16(); 



            I32 ReadI32(); 



            I64 ReadI64(); 



            U08 ReadU08(); 



            U16 ReadU16(); 



            U32 ReadU32(); 



            U64 ReadU64(); 



            float ReadFloat(); 



            double ReadDouble(); 



            a_string ReadString(); 



            a_string ReadUtf8String(); 



            a_wstring ReadWString(); 



            U64 ReadBytes(void * bytes, U64 length); 



            bool Analyze(CMemory & data);



            IInterface * QueryInterface(U32 iid); 



    };  //end class CMessage



} //end namespace electron



#endif
