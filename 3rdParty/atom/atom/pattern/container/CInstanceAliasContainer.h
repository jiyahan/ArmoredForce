#ifndef CINSTANCEALIASCONTAINER_H
#define CINSTANCEALIASCONTAINER_H
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



    template <class T>
    class CInstanceAliasContainer : public IInstanceAliasContainer<T>
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif
			
			
			
            CInstanceAliasSet<T> aliases[CONTAINER_QUEUE];




        public:


            CInstanceAliasContainer(): 
            nest(NULL)
			#ifdef _SHIPPING_
			,cast(NULL)
			#endif
            {
            }


            virtual ~CInstanceAliasContainer()
            {
            }


            virtual int  IncRef()
            {
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


            virtual int  DecRef()
            {
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


            virtual int  GetRef()
            {
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


            virtual IInterface *  QueryInterface(U32 iid)
            {
                IInterface * result = NULL;
                if( nest && iid ) {
                    result = nest -> QueryInterface( iid );
                }
                return result;
            }


            virtual void  SetNest(IInterface * value)
            {
				if( value ) 
				{
					nest = value;
					#ifdef _SHIPPING_
					cast = dynamic_cast<IReferencedInterface *>( nest );
					#endif
				}
            }


            virtual bool  Insert(const T & alias, CObjectPtr & instance)
            {
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


            virtual CObjectPtr  Obtain(const T & alias)
            {
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


            virtual void  Obtain(std::vector<T, atom_allocator<T> > & out)
            {
                for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
                    aliases[i].Obtain( out );
                }
            }


            virtual bool  Inside(const T & alias)
            {
	        	atom_hash<T> hasher;
                U64 data = hasher( alias );
                U64 node = data % CONTAINER_QUEUE;
                return( 0 != aliases[node].Obtain(alias) );
            }


            virtual U64  Amount()
            {
                U64 result = 0;
                for( size_t i = 0; i < CONTAINER_QUEUE; ++ i ) {
                    result += aliases[i].Amount();
                }
                return result;
            }


            virtual bool  Remove(const T & alias)
            {
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


            virtual void  RemoveAll()
            {
	        	std::vector<T, atom_allocator<T> > indices;
	        	Obtain( indices );
	        	for( size_t i = 0, j = indices.size(); i < j; ++ i ) {
	        		Remove( indices[i] );
	        	}
            }

    };  //end class CInstanceAliasContainer



} //end namespace atom



#endif
