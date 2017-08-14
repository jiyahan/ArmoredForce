#include "CInstanceContainable.h"
#include "../../utility/stl/stl_extend.h"
#include "../../utility/tool/CCriticalSectionScope.h"


atom::CInstanceContainable::CInstanceContainable() 
{
}

atom::CInstanceContainable::~CInstanceContainable() 
{
    RemoveAll();
}

bool atom::CInstanceContainable::Insert(CObjectPtr & instance) 
{
    bool result = false;
    if( instance )
    {
    	// ֱ�ӳ��Բ�������������ʵ��ָ��ԣ�����ɹ��������
    	// ��������δ�����ڶ����б��ڣ�
    	clog.Enter();
        pair<CInstanceContainableBind::iterator, bool> 
    		retval = instances.insert( 
    		make_pair( instance -> GetName(), instance ) );
    	result = retval.second;
    	clog.Leave();
    }
    return result;
}

atom::CObjectPtr atom::CInstanceContainable::Obtain(U64 instance_name) 
{
    CObjectPtr result;
    if( instance_name )
    {
        clog.Enter();
        CInstanceContainableBind::
    		iterator it = instances.find( instance_name );
    	if( it != instances.end() ) {
    		result = it -> second;
    	}
        clog.Leave();
    }
    return result;
}

void atom::CInstanceContainable::Obtain(CU64Array & out) 
{
    CCriticalSectionScope scope( clog );
    out.reserve( instances.size() + out.size() );
    std::transform( instances.begin(), instances.end(), 
        back_inserter(out), atom::select1st<CInstanceContainableBind::value_type>() );
}

bool atom::CInstanceContainable::Inside(U64 instance_name) 
{
    bool result = false;
    if( instance_name )
    {
    	CCriticalSectionScope scope( clog );
        result = ( instances.find(instance_name) != instances.end() );
    }
    return result;
}

U64 atom::CInstanceContainable::Amount() 
{
    CCriticalSectionScope scope( clog );
    return static_cast<U64>( instances.size() );
}

bool atom::CInstanceContainable::Remove(U64 instance_name) 
{
    bool result = false;
	if( instance_name )
	{
        clog.Enter();
        CInstanceContainableBind::
            iterator it = instances.find( instance_name );
        if( it != instances.end() ) {
			instances.erase( it ); result = true;
		}
        clog.Leave();
	}
	return result;
}

void atom::CInstanceContainable::RemoveAll() 
{
    CCriticalSectionScope scope( clog );
    instances.clear();
}
