#ifndef CFILESTREAM_H
#define CFILESTREAM_H
#include "../../interface/IFileStream.h"
#include "../../interface/IInterface.h"
#include "../../utility/stl/a_string.h"
#include "../../utility/stl/a_wstring.h"
#include "../thread/CCriticalSection.h"
#include "../memory/CMemory.h"



namespace atom
{



    class CFileStream : public IFileStream
    {


        private:


            IInterface * nest;



            bool read;



            U64 full;



            U64 site;



            FILE * file;



            #if defined(__linux) || defined(__APPLE__)
            a_string name;
            #endif



            #if defined(_WIN32)
            a_wstring name;
            #endif



            CCriticalSection section;




        public:

            CFileStream(); 



            virtual ~CFileStream(); 



            #if defined(__linux) || defined(__APPLE__)
            void SetDevice(const char * filepath); 
            #endif



            #if defined(_WIN32)
            void SetDevice(const wchar_t * filepath); 
            #endif



            void SetOffset(U64 offset); 



            #if defined(__linux) || defined(__APPLE__)
            U64 GetLength(const char * filepath); 
            #endif



            #if defined(_WIN32)
            U64 GetLength(const wchar_t * filepath); 
            #endif



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual char Read(); 



            virtual U64 Read(void * value, U64 length); 



            virtual U64 Read(void * value, U64 offset, U64 length); 



            virtual void Write(char value); 



            virtual void Write(const void * value, U64 length); 



            virtual void Write(const void * value, U64 offset, U64 length); 



            virtual void Close(); 



            virtual void Truncate(); 



            virtual void Flush(); 



            virtual U64 Available(); 



            virtual U64 Length(); 



            virtual void Mark(U64 position); 



            virtual void Reset(); 



            virtual I64 Skip(I64 bytes); 



            virtual bool Assign(CMemory & data); 



            virtual bool Swap(CMemory & data); 



            virtual bool Clone(CMemory & data); 



            virtual bool Open(); 



            virtual bool IsReadOnly(); 



    };  //end class CFileStream


}//end namespace atom


#endif
