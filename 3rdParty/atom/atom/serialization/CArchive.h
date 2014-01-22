#ifndef CARCHIVE_H
#define CARCHIVE_H
#include "../Common.h"
#include "../os/memory/CMemory.h"
#include "../interface/IInterface.h"
#include "../stream/memory/CStream.h"
#include "../stream/wrapper/CImportableWrapper.h"
#include "../stream/wrapper/CExportableWrapper.h"
#include "CExportArchive.h"
#include "CImportArchive.h"


namespace atom
{
    

    
    class CArchive : public IInterface
    {


        private:


            CStream stream;



            CImportableWrapper importable;



            CExportableWrapper exportable;



            CExportArchive export_archive;



            CImportArchive import_archive;




        public:

            CArchive(); 



            virtual ~CArchive(); 



            virtual IInterface * QueryInterface(U32 iid); 



            bool Assign(CMemory & data); 



            bool Clone(CMemory & data); 



            void Clear(); 



            template <class T>
            inline CArchive & operator <<(T & value)
            {
                export_archive.Bind( value );
                return( *this );
            }



            template <class T>
            inline CArchive & operator <<(const T & value)
            {
                export_archive.Bind( value );
                return( *this );
            }



            template <class T>
            inline CArchive & operator >>(T & value)
            {
                import_archive.Bind( value );
                return( *this );
            }



    };  //end class CArchive



} //end namespace atom



#endif
