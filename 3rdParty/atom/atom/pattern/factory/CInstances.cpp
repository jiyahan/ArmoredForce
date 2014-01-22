#include "CInstances.h"
#include "../../utility/tool/CCriticalSectionScope.h"


atom::CInstances::CInstances() 
{
}

atom::CInstances::~CInstances() 
{
}

bool atom::CInstances::Insert(CReferencedObject * instance) 
{
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

bool atom::CInstances::Inside(U64 name) 
{
    CCriticalSectionScope scope( section );
    return( instances.find(name) != instances.end() );
}

atom::CObjectPtr atom::CInstances::Obtain(U64 name) 
{
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

void atom::CInstances::Obtain(CU64Array & indices) 
{
    CCriticalSectionScope scope( section );
    std::transform( instances.begin(), instances.end(), 
        back_inserter(indices), atom::select1st<CInstancesBind::value_type>() );
}

U64 atom::CInstances::Amount() 
{
    CCriticalSectionScope scope( section );
    return static_cast<U64>( instances.size() );
}

atom::CReferencedObject * atom::CInstances::Remove(U64 name, bool & exist, bool force) 
{
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
