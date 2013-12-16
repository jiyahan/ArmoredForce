#ifndef CMEMBERS_H
#define CMEMBERS_H
//Begin section for file CMembers.h
//TODO: Add definitions that you want preserved
//End section for file CMembers.h
#include "../../interface/IInterface.h"
#include "../../os/callstack/CCallStack.h"
#include "../../log/CLog.h"
#include "../../stream/memory/CStream.h"
#include "../../stream/wrapper/CExportableWrapper.h"
#include "../../stream/wrapper/CImportableWrapper.h"
#include "../../serialization/CImportArchive.h"
#include "../../serialization/CExportArchive.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "CMembersBind.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMembers : public IInterface
    {

        //Begin section for atom::CMembers
        //TODO: Add attributes that you want preserved
        //End section for atom::CMembers

        private:
			//当头状态
			int m_state;

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CStream stream;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CExportableWrapper exportable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportableWrapper importable;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CImportArchive import_archive;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CExportArchive export_archive;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMembersBind member;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CMembers()
            {
                //TODO Auto-generated method stub
                stream        .SetNest( this );
                importable    .SetNest( this );
                exportable    .SetNest( this );
                import_archive.SetNest( this );
                export_archive.SetNest( this );
    
                importable    .Attach ( this );
                exportable    .Attach ( this );
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CMembers()
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual IInterface * QueryInterface(U32 iid)
            {
                //TODO Auto-generated method stub
                IInterface * result = NULL;
                switch( iid )
                {
                case IID_STREAM:
                    result = & stream;
                    break;
                case IID_IMPORTABLE:
                    result = & importable;
                    break;
                case IID_EXPORTABLE:
                    result = & exportable;
                    break;
                }
                return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Clear()
            {
                //TODO Auto-generated method stub
                stream.Reset();
                member.clear();
            }

			//1写入内存2读内存
			void SetState(int state)
			{
				m_state=state;
			}

			template<typename T>
			inline bool Bind(const char* name, T& t)
			{
				bool result = false;
				if(m_state==1)
				{
					result= Attach(name,t);
				}
				else
				{
					result=Detach(name,t);
				}
				return result;
			}



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			template<class T>
            inline bool Attach(const char * name, T & value) 
            {
                //TODO Auto-generated method stub
				bool result = false;
				if( name )
				{
					CMemory data;
                    export_archive.Bind( value );
                    stream.Swap( data );

					pair<CMembersBind::iterator, 
						bool> retval = member.insert( make_pair(name, data) );
					result = retval.second;
					if( !result )
					{
						retval.first -> second = data;

                        a_string stack;
                        CCallStack::RecordCallStack( stack );

                        CLog log;
                        log << "Reserialize member: " << name << "stack: " << stack << end_error;
					}
				}
	        	return result;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			template<class T>
            inline bool Detach(const char * name, T & value)
            {
                //TODO Auto-generated method stub
				bool result = false;
				if( name )
				{
					CMembersBind::
						iterator it = member.find( name );
					if( it != member.end() )
					{
						result = true;
						stream.Assign( it -> second );
                        import_archive.Bind( value );
                        stream.Close();
					}
					else
					{
                        a_string stack;
                        CCallStack::RecordCallStack( stack );

                        CLog log;
                        log << "FAILED deserialize member: " << name << "stack: " << stack << end_error;
					}
				}
	        	return result;
            }



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			template<class A>
			inline void Serialize(A & ar, bool save)
			{
				//TODO Auto-generated method stub
                UNREFERENCED_PARAMETER( save );
				ar.Bind( member );
			}



    };  //end class CMembers



} //end namespace atom



#endif
