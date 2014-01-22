#ifndef CEXPORTARCHIVE_H
#define CEXPORTARCHIVE_H
#include "../interface/IEmbedInterface.h"
#include "../interface/IInterface.h"
#include "tagSerializer.h"
#include "../utility/stl/a_string.h"
#include "../utility/stl/a_wstring.h"



namespace atom
{


    
    class CExportArchive : public IEmbedInterface
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CExportArchive(); 



            virtual ~CExportArchive(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            void Bind(bool & value); 



            void Bind(char & value); 



            void Bind(I08 & value); 



            void Bind(I16 & value); 



            void Bind(I32 & value); 



            void Bind(I64 & value); 



            void Bind(U08 & value); 



            void Bind(U16 & value); 



            void Bind(U32 & value); 



            void Bind(U64 & value); 



            void Bind(float & value); 



            void Bind(double & value); 



            void Bind(a_string & value); 



            void Bind(a_wstring & value); 



            void Bind(void * buffer, U64 length); 



            template <class T>
            void Bind(T & value)
            {
	        	tagSerializer<CExportArchive, T, true>::Serialize( *this, value );
            }



            template <class T>
            void Bind(const T & value)
            {
                Bind( const_cast<T &>(value) );
            }



    };  //end class CExportArchive



} //end namespace atom



#endif
