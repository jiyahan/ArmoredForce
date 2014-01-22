#ifndef CMEMBERS_H
#define CMEMBERS_H
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



    class CMembers : public IInterface
    {


        private:
			//当头状态
			int m_state;

            CStream stream;



            CExportableWrapper exportable;



            CImportableWrapper importable;



            CImportArchive import_archive;



            CExportArchive export_archive;



            CMembersBind member;




        public:

            inline CMembers()
            {
                stream        .SetNest( this );
                importable    .SetNest( this );
                exportable    .SetNest( this );
                import_archive.SetNest( this );
                export_archive.SetNest( this );
    
                importable    .Attach ( this );
                exportable    .Attach ( this );
            }



            inline virtual ~CMembers()
            {
            }



            inline virtual IInterface * QueryInterface(U32 iid)
            {
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



            inline void Clear()
            {
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



			template<class T>
            inline bool Attach(const char * name, T & value) 
            {
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



			template<class T>
            inline bool Detach(const char * name, T & value)
            {
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



			template<class A>
			inline void Serialize(A & ar, bool save)
			{
                UNREFERENCED_PARAMETER( save );
				ar.Bind( member );
			}



    };  //end class CMembers



} //end namespace atom



#endif
