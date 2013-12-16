#include "CInstances.h"
#include "../../utility/tool/CCriticalSectionScope.h"
//Begin section for file CInstances.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstances.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstances::CInstances() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstances::~CInstances() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstances::Insert(CReferencedObject * instance) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( instance && instance -> GetName() )
    {
    	section.Enter();
        pair<CInstancesBind::iterator, bool> retval =
    	    instances.insert( make_pair( instance -> GetName(), instance ) );
        result = retval.second;
        section.Leave();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstances::Inside(U64 name) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    return( instances.find(name) != instances.end() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstances::Obtain(U64 name) 
{
    //TODO Auto-generated method stub
    CObjectPtr result;
    if( name )
    {
    	section.Enter();
		CInstancesBind::iterator it = instances.find( name );
		if( it != instances.end() ) {
            result = it -> second;
		}
		section.Leave();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstances::Obtain(CU64Array & indices) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    std::transform( instances.begin(), instances.end(), 
        back_inserter(indices), atom::select1st<CInstancesBind::value_type>() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstances::Amount() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( section );
    return static_cast<U64>( instances.size() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CReferencedObject * atom::CInstances::Remove(U64 name, bool & exist, bool force) 
{
    //TODO Auto-generated method stub
    CReferencedObject * result(NULL);
	exist = false;

    CCriticalSectionScope scope( section );
	CInstancesBind::iterator it = instances.find( name );	
	if( it != instances.end() )
	{
		bool erase = true; exist = true;
		if( it -> second )
		{
            erase = ( it -> second -> GetRef() == 0 );
            if( erase ) {
				result = it -> second;
			} 
            else
			if( force ) {
				result = it -> second; erase = true;
			}
		}
		
		if( erase ) instances.erase( it );
	}
    return result;
}
