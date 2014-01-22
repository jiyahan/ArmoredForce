#ifndef CINSTANCEALIASSET_H
#define CINSTANCEALIASSET_H
#include "CInstanceAliasSetBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



    template <class T>
    class CInstanceAliasSet
    {


        private:


            typename CInstanceAliasSetBind<T>::type aliases;



            CCriticalSection section;




        public:


            CInstanceAliasSet()
            {
            }


            virtual ~CInstanceAliasSet()
            {
            }


            bool  Insert(const T & alias, U64 name)
            {
			    bool result = false;
			    if( name )
			    {
			    	CCriticalSectionScope scope( section );
			    	pair<typename CInstanceAliasSetBind<T>::
			    		type::iterator, bool> 
			    		retval = aliases.insert( make_pair(alias, name) );
			    	result = retval.second;
			    }
			    return result;
            }


            U64  Obtain(const T & alias)
            {
			    U64 result = 0;
			    CCriticalSectionScope scope( section );
			    typename CInstanceAliasSetBind<T>::
			    	type::iterator it = aliases.find( alias );
			    if( it != aliases.end() ) {
			    	result = it -> second;
			    }
			    return result;
            }


            void  Obtain(std::vector<T, atom_allocator<T> > & out)
            {
			    CCriticalSectionScope scope( section );
			    for( typename CInstanceAliasSetBind<T>::type::
                    iterator it = aliases.begin(); it != aliases.end(); ++ it ) {
			    	out.push_back( it -> first );
			    }
            }


            U64  Amount()
            {
			    CCriticalSectionScope scope( section );
                return aliases.size();
            }


            bool  Remove(const T & alias)
            {
			    bool result = false;
			    CCriticalSectionScope scope( section );
			    typename CInstanceAliasSetBind<T>::
			    	type::iterator it = aliases.find( alias );
			    if( it != aliases.end() ) {
			    	aliases.erase( it ); result = true;
			    }
			    return result;
            }


            bool  RemoveAll()
            {
			    CCriticalSectionScope scope( section );
			    aliases.clear();
                return true;
            }


    };  //end class CInstanceAliasSet



} //end namespace atom



#endif
