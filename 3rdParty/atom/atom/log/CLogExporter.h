#ifndef CLOGEXPORTER_H
#define CLOGEXPORTER_H
//Begin section for file CLogExporter.h
//TODO: Add definitions that you want preserved
//End section for file CLogExporter.h
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



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CLogExporter : public IEmbedInterface
    {

        //Begin section for atom::CLogExporter
        //TODO: Add attributes that you want preserved
        //End section for atom::CLogExporter

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CLogExporter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CLogExporter(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int IncRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int DecRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int GetRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetNest(IInterface * nest); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(bool & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(char & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I08 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I16 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I32 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(I64 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U08 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U16 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U32 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(U64 & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(float & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(double & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(a_string & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(a_wstring & value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void Bind(void * buffer, U64 length); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            void Bind(T & value)
            {
                //TODO Auto-generated method stub
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



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template <class T>
            void Bind(const T & value)
            {
                //TODO Auto-generated method stub
                Bind( const_cast<T &>(value) );
            }



    };  //end class CLogExporter



} //end namespace atom



#endif
