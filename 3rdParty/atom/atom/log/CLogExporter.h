#ifndef CLOGEXPORTER_H
#define CLOGEXPORTER_H
#include "../interface/IEmbedInterface.h"
#include "../interface/IInterface.h"
#include "../utility/stl/a_string.h"
#include "../utility/stl/a_wstring.h"
#include "../serialization/tagSerializer.h"
#include "../interface/ILogArchive.h"
#include "../utility/tool/CInterface.h"
#include "../enumeration/INTERFACE_ID.h"



namespace atom
{



    class CLogExporter : public IEmbedInterface
    {


        private:


            IInterface * nest;




        public:

            CLogExporter(); 



            virtual ~CLogExporter(); 



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
                CInterface<ILogArchive> segment;
                if( segment.Mount(this, IID_LOG_ARCHIVE) )
                {
                    segment -> Append( "{ " );
                    segment -> Append( typeid(T).name() );
                    segment -> Append( " " );

                    tagSerializer<CLogExporter, T, true>::Serialize( *this, value );

                    segment -> Append( " }" );
                }
            }



            template <class T>
            void Bind(const T & value)
            {
                Bind( const_cast<T &>(value) );
            }



    };  //end class CLogExporter



} //end namespace atom



#endif
