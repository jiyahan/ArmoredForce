#ifndef CXMLDOCUMENTPTR_H
#define CXMLDOCUMENTPTR_H
#include "../../interface/IXmlDocumentNode.h"
#include "../../interface/IReferencedObject.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"



namespace atom
{



	class CXmlDocumentPtr
	{


		private:


			IXmlDocumentNode * node;



			U64 name;




		public:

			inline CXmlDocumentPtr() : 
			node(NULL),name(0)
			{
			} 



			inline CXmlDocumentPtr(IReferencedObject * object) : 
			node(NULL),name(0)
			{
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



			inline CXmlDocumentPtr(const CXmlDocumentPtr & object) : 
			node(NULL),name(0)
			{
				*this = object;
			}



			inline virtual ~CXmlDocumentPtr()
			{
				SAFE_DECREF( node );

				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}
			}



			inline CXmlDocumentPtr & operator = (const CXmlDocumentPtr & value)
			{
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



			inline CXmlDocumentPtr & operator = (IReferencedObject * object)
			{
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



			inline IXmlDocumentNode * operator ->()
			{
				return node;
			}



			inline operator IXmlDocumentNode * ()
			{
				return node;
			}



	};  //end class CXmlDocumentPtr



} //end namespace atom



#endif
