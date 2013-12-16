#ifndef CINSTANCEALIASSET_H
#define CINSTANCEALIASSET_H
//Begin section for file CInstanceAliasSet.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceAliasSet.h
#include "CInstanceAliasSetBind.h"
#include "../../os/thread/CCriticalSection.h"
#include "../../utility/tool/CCriticalSectionScope.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    class CInstanceAliasSet
    {

        //Begin section for atom::CInstanceAliasSet
        //TODO: Add attributes that you want preserved
        //End section for atom::CInstanceAliasSet

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typename CInstanceAliasSetBind<T>::type aliases;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CCriticalSection section;




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CInstanceAliasSet()
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CInstanceAliasSet()
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool  Insert(const T & alias, U64 name)
            {
                //TODO Auto-generated method stub
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


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64  Obtain(const T & alias)
            {
                //TODO Auto-generated method stub
			    U64 result = 0;
			    CCriticalSectionScope scope( section );
			    typename CInstanceAliasSetBind<T>::
			    	type::iterator it = aliases.find( alias );
			    if( it != aliases.end() ) {
			    	result = it -> second;
			    }
			    return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            void  Obtain(std::vector<T, atom_allocator<T> > & out)
            {
                //TODO Auto-generated method stub
			    CCriticalSectionScope scope( section );
			    for( typename CInstanceAliasSetBind<T>::type::
                    iterator it = aliases.begin(); it != aliases.end(); ++ it ) {
			    	out.push_back( it -> first );
			    }
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U64  Amount()
            {
                //TODO Auto-generated method stub
			    CCriticalSectionScope scope( section );
                return aliases.size();
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool  Remove(const T & alias)
            {
                //TODO Auto-generated method stub
			    bool result = false;
			    CCriticalSectionScope scope( section );
			    typename CInstanceAliasSetBind<T>::
			    	type::iterator it = aliases.find( alias );
			    if( it != aliases.end() ) {
			    	aliases.erase( it ); result = true;
			    }
			    return result;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            bool  RemoveAll()
            {
                //TODO Auto-generated method stub
			    CCriticalSectionScope scope( section );
			    aliases.clear();
                return true;
            }


    };  //end class CInstanceAliasSet



} //end namespace atom



#endif
