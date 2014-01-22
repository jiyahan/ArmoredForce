#ifndef CXMLELEMENTPTR_H
#define CXMLELEMENTPTR_H
#include "../../interface/IXmlElementNode.h"
#include "../../interface/IReferencedObject.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"



namespace atom
{



	class CXmlElementPtr
	{


		private:


			IXmlElementNode * node;



			U64 name;




		public:

			inline CXmlElementPtr() : 
			node(NULL),name(0)
			{
			} 



			inline CXmlElementPtr(IReferencedObject * object) : 
			node(NULL),name(0)
			{
				if( object )
				{
					IInterface * pointer = 
						object -> QueryInterface( IID_XML_ELEMENT_NODE );
                    if( pointer )
                    {
						node = dynamic_cast<IXmlElementNode *>( pointer );
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



			inline CXmlElementPtr(const CXmlElementPtr & object) : 
			node(NULL),name(0)
			{
				*this = object;
			}



			inline virtual ~CXmlElementPtr()
			{
				SAFE_DECREF( node );

				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}
			}



			inline CXmlElementPtr & operator = (const CXmlElementPtr & value)
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



			inline CXmlElementPtr & operator = (IReferencedObject * object)
			{
				SAFE_DECREF( node );
				
				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}

				if( object )
				{
					IInterface * pointer = 
						object -> QueryInterface( IID_XML_ELEMENT_NODE );
                    if( pointer )
                    {
						node = dynamic_cast<IXmlElementNode *>( pointer );
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



			inline IXmlElementNode * operator ->()
			{
				return node;
			}



			inline operator IXmlElementNode * ()
			{
				return node;
			}



	};  //end class CXmlElementPtr



} //end namespace atom



#endif
