#ifndef CXMLELEMENTPTR_H
#define CXMLELEMENTPTR_H
//Begin section for file CXmlElementPtr.h
//TODO: Add definitions that you want preserved
//End section for file CXmlElementPtr.h
#include "../../interface/IXmlElementNode.h"
#include "../../interface/IReferencedObject.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../../enumeration/INTERFACE_ID.h"



namespace atom
{



	//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
	class CXmlElementPtr
	{

		//Begin section for atom::CXmlElementPtr
		//TODO: Add attributes that you want preserved
		//End section for atom::CXmlElementPtr

		private:


			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IXmlElementNode * node;



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			U64 name;




		public:

			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlElementPtr() : 
			node(NULL),name(0)
			{
				//TODO Auto-generated method stub
			} 



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlElementPtr(IReferencedObject * object) : 
			node(NULL),name(0)
			{
				//TODO Auto-generated method stub
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



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlElementPtr(const CXmlElementPtr & object) : 
			node(NULL),name(0)
			{
				//TODO Auto-generated method stub
				*this = object;
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline virtual ~CXmlElementPtr()
			{
				//TODO Auto-generated method stub
				SAFE_DECREF( node );

				if( name ) {
					CInstanceLife::GetInstance() -> Decrease( name );
					name = 0;
				}
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline CXmlElementPtr & operator = (const CXmlElementPtr & value)
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
			inline CXmlElementPtr & operator = (IReferencedObject * object)
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



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline IXmlElementNode * operator ->()
			{
				//TODO Auto-generated method stub
				return node;
			}



			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			inline operator IXmlElementNode * ()
			{
				//TODO Auto-generated method stub
				return node;
			}



	};  //end class CXmlElementPtr



} //end namespace atom



#endif
