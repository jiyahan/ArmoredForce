#ifndef CINSTANCEALIASCONTAINER_H
#define CINSTANCEALIASCONTAINER_H
//Begin section for file CInstanceAliasContainer.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceAliasContainer.h
#include "../../interface/IInstanceAliasContainer.h"
#include "../../interface/IInterface.h"
#include "../../interface/IInstanceContainer.h"
#include "../../enumeration/INTERFACE_ID.h"
#include "../../utility/tool/CObjectPtr.h"
#include "../../utility/tool/CInterface.h"
#include "../../utility/stl/stl_extend.h"
#include "CInstanceAliasSet.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    class CInstanceAliasContainer : public IInstanceAliasContainer<T>
    {

        //Begin section for atom::CInstanceAliasContainer
        //TODO: Add attributes that you want preserved
        //End section for atom::CInstanceAliasContainer

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



			#ifdef _SHIPPING_
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
			IReferencedInterface * cast;
			#endif
			
			
			
			//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceAliasSet<T> aliases[CONTAINER_QUEUE];




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceAliasContainer(): 
            nest(NULL)
			#ifdef _SHIPPING_
			,cast(NULL)
			#endif
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CInstanceAliasContainer()
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int  IncRef()
            {
                //TODO Auto-generated method stub
				int result = 0;
				#ifdef _SHIPPING_
				if( cast )
				{
					result = cast -> IncRef();
				}
				#else
				if( nest )
				{
					IReferencedInterface * refered = 
						dynamic_cast<IReferencedInterface *>( nest );
					if( refered ) {
						result = refered -> IncRef();
					}
				}
				#endif
				return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int  DecRef()
            {
                //TODO Auto-generated method stub
				int result = 0;
				#ifdef _SHIPPING_
				if( cast )
				{
					result = cast -> DecRef();
				}
				#else
				if( nest )
				{
					IReferencedInterface * refered = 
						dynamic_cast<IReferencedInterface *>( nest );
					if( refered ) {
						result = refered -> DecRef();
					}
				}
				#endif
				return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int  GetRef()
            {
                //TODO Auto-generated method stub
				int result = 0;
				#ifdef _SHIPPING_
				if( cast )
				{
					result = cast -> GetRef();
				}
				#else
				if( nest )
				{
					IReferencedInterface * refered = 
						dynamic_cast<IReferencedInterface *>( nest );
					if( refered ) {
						result = refered -> GetRef();
					}
				}
				#endif
				return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface *  QueryInterface(U32 iid)
            {
                //TODO Auto-generated method stub
                IInterface * result = NULL;
                if( nest && iid ) {
                    result = nest -> QueryInterface( iid );
                }
                return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void  SetNest(IInterface * value)
            {
                //TODO Auto-generated method stub
				if( value ) 
				{
					nest = value;
					#ifdef _SHIPPING_
					cast = dynamic_cast<IReferencedInterface *>( nest );
					#endif
				}
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool  Insert(const T & alias, CObjectPtr & instance)
            {
                //TODO Auto-generated method stub
	        	bool result = false;
	        	if( instance )
	        	{
	        		atom_hash<T> hasher;
                    U64 data = hasher( alias );
                    U64 node = data % CONTAINER_QUEUE;
                    U64 name = instance -> GetName();

                    if( name && aliases[node].Insert(alias, name) )
                    {
	        		    // 向容器内添加对象；
                        CInterface<IInstanceContainer> segment;
                        if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
                            result = segment -> Insert( instance );
	        		    }
	        		
	        		    // 如果失败，则取消加入该别名；
	        		    if( false == result ) {
                            aliases[node].Remove( alias );
                        }
                    }
	        	}
	        	return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual CObjectPtr  Obtain(const T & alias)
            {
                //TODO Auto-generated method stub
	        	atom_hash<T> hasher;
                U64 data = hasher( alias );
                U64 node = data % CONTAINER_QUEUE;
                U64 name = aliases[node].Obtain( alias );

                CObjectPtr result;
	        	if( name )
	        	{
                    CInterface<IInstanceContainer> segment;
                    if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
	        			result = segment -> Obtain( name );
	        		}
	        	}
	        	return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void  Obtain(std::vector<T, atom_allocator<T> > & out)
            {
                //TODO Auto-generated method stub
                for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
                    aliases[i].Obtain( out );
                }
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool  Inside(const T & alias)
            {
                //TODO Auto-generated method stub
	        	atom_hash<T> hasher;
                U64 data = hasher( alias );
                U64 node = data % CONTAINER_QUEUE;
                return( 0 != aliases[node].Obtain(alias) );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual U64  Amount()
            {
                //TODO Auto-generated method stub
                U64 result = 0;
                for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
                    result += aliases[i].Amount();
                }
                return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual bool  Remove(const T & alias)
            {
                //TODO Auto-generated method stub
	        	atom_hash<T> hasher;
                U64 data = hasher( alias );
                U64 node = data % CONTAINER_QUEUE;
                U64 name = aliases[node].Obtain( alias );

                bool result = false;
                if( name )
                {
                    CInterface<IInstanceContainer> segment;
                    if( segment.Mount(this, IID_INSTANCE_CONTAINER) ) {
                        result = segment -> Remove( name );
                    }

                    if( result ) {
                        aliases[node].Remove( alias );
                    }
                }
                return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void  RemoveAll()
            {
                //TODO Auto-generated method stub
	        	std::vector<T, atom_allocator<T> > indices;
	        	Obtain( indices );
	        	for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
	        		Remove( indices[i] );
	        	}
            }

    };  //end class CInstanceAliasContainer



} //end namespace atom



#endif
