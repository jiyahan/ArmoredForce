#ifndef CFILE_H
#define CFILE_H
#include "../../interface/IInterface.h"
#include "CFileStream.h"
#include "../../utility/stl/a_string.h"



namespace atom
{



    class CFile : public IInterface
    {


        private:


            CFileStream stream;



        public:

            CFile(const char * name); 



            CFile(const wchar_t * name); 



            virtual ~CFile(); 



            virtual IInterface * QueryInterface(U32 iid); 



            bool Open(); 



            void Mark(U64 position); 



            void Close(); 



            U64 Length(); 



            bool IsReadOnly(); 



            static bool Erase(const char * file); 

    
    
            static bool Erase(const wchar_t * file); 



            static CMemory LoadFile(const char * file); 



            static CMemory LoadFile(const wchar_t * file); 



    };  //end class CFile



}//end namespace atom


#endif
