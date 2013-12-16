#ifndef CXMLDOCUMENTPTR_H
#define CXMLDOCUMENTPTR_H
//Begin section for file CXmlDocumentPtr.h
//TODO: Add definitions that you want preserved
//End section for file CXmlDocumentPtr.h
#include "../../interface/IXmlDocumentNode.h"
#include "../../interface/IReferencedObject.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CXmlDocumentPtr
	{

		//Begin section for atom::CXmlDocumentPtr
		//TODO: Add attributes that you want preserved
		//End section for atom::CXmlDocumentPtr

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IXmlDocumentNode * node;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U64 name;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlDocumentPtr() : 
			node(NULL),name(0)
			{
				//TODO Auto-generated method stub
			} 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlDocumentPtr(IReferencedObject * object) : 
			node(NULL),name(0)
			{
				//TODO Auto-generated method stub
				if( object )
				{
					IInterface * pointer = 
						object -> QueryInterface( IID_XML_DOCUMENT_NODE );
                    if( pointer )
                    {
						node = dynamic_cast<IXmlDocumentNode *>( pointer );
                        if( node == NULL )
                        { 
                            IReferencedInterface * refered = 
                                dynamic_cast<IReferencedInterface *>( pointer );
                            SAFE_DECREF( refered );
                        }
                    }

					if( node )
					{
						name = object -> GetName();
						if( name ) {
							CInstanceLife::GetInstance() -> Increase( name );
						}
					}
				}
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlDocumentPtr(const CXmlDocumentPtr & object) : 
			node(NULL),name(0)
			{
				//TODO Auto-generated method stub
				*this = object;
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline virtual ~CXmlDocumentPtr()
			{
				//TODO Auto-generated method stub
				SAFE_DECREF( node );

				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlDocumentPtr & operator = (const CXmlDocumentPtr & value)
			{
				//TODO Auto-generated method stub
				SAFE_DECREF( node );
				
				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}

				if( value.node && value.node -> IncRef() ) {
					node = value.node;
				}

				name = value.name;
				if( name ) {
					CInstanceLife::GetInstance() -> Increase( name );
				}

				return( * this );
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlDocumentPtr & operator = (IReferencedObject * object)
			{
				//TODO Auto-generated method stub
				SAFE_DECREF( node );
				
				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}

				if( object )
				{
					IInterface * pointer = 
						object -> QueryInterface( IID_XML_DOCUMENT_NODE );
                    if( pointer )
                    {
						node = dynamic_cast<IXmlDocumentNode *>( pointer );
                        if( node == NULL )
                        { 
                            IReferencedInterface * refered = 
                                dynamic_cast<IReferencedInterface *>( pointer );
                            SAFE_DECREF( refered );
                        }
                    }

					if( node )
					{
						name = object -> GetName();
						if( name ) {
							CInstanceLife::GetInstance() -> Increase( name );
						}
					}
				}

				return( * this );
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline IXmlDocumentNode * operator ->()
			{
				//TODO Auto-generated method stub
				return node;
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline operator IXmlDocumentNode * ()
			{
				//TODO Auto-generated method stub
				return node;
			}



	};  //end class CXmlDocumentPtr



} //end namespace atom



#endif
