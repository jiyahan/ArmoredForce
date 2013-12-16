#include "CInstanceContainable.h"
#include "../../utility/stl/stl_extend.h"
#include "../../utility/tool/CCriticalSectionScope.h"
//Begin section for file CInstanceContainable.cpp
//TODO: Add definitions that you want preserved
//End section for file CInstanceContainable.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceContainable::CInstanceContainable() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CInstanceContainable::~CInstanceContainable() 
{
    //TODO Auto-generated method stub
    RemoveAll();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceContainable::Insert(CObjectPtr & instance) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( instance )
    {
    	// 直接尝试插入对象的名称与实例指针对，如果成功，则表明
    	// 对象名尚未存在于对象列表内；
    	clog.Enter();
        pair<CInstanceContainableBind::iterator, bool> 
    		retval = instances.insert( 
    		make_pair( instance -> GetName(), instance ) );
    	result = retval.second;
    	clog.Leave();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CObjectPtr atom::CInstanceContainable::Obtain(U64 instance_name) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainable::Obtain(CU64Array & out) 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    out.reserve( instances.size() + out.size() );
    std::transform( instances.begin(), instances.end(), 
        back_inserter(out), atom::select1st<CInstanceContainableBind::value_type>() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceContainable::Inside(U64 instance_name) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( instance_name )
    {
    	CCriticalSectionScope scope( clog );
        result = ( instances.find(instance_name) != instances.end() );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CInstanceContainable::Amount() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    return static_cast<U64>( instances.size() );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CInstanceContainable::Remove(U64 instance_name) 
{
    //TODO Auto-generated method stub
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

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CInstanceContainable::RemoveAll() 
{
    //TODO Auto-generated method stub
    CCriticalSectionScope scope( clog );
    instances.clear();
}
