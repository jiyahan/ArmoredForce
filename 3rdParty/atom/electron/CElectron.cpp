#include "CElectron.h"
//Begin section for file CElectron.cpp
//TODO: Add definitions that you want preserved
//End section for file CElectron.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CElectron::active = false;

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectron::Presetup() 
{
    //TODO Auto-generated method stub
	if( active == false )
	{
        CElectronAllocator  ::CreateInstance();
        CMessageAllocator   ::CreateInstance();
        CConnectionScheduler::CreateInstance();

		// Attach allocator
		CObjectPtr allocator = CElectronAllocator::GetInstance();
		CInstanceFactory::GetInstance() -> Attach( allocator );
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CElectron::Initiate(U32 thread_amount) 
{
    //TODO Auto-generated method stub
    bool result = false;
    if( active == false )
    {
        active = true;
        result = true;

		result &= 
        CMessageAllocator   ::GetInstance() -> Initiate();
		result &=
        CConnectionScheduler::GetInstance() -> Initiate( thread_amount );
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CElectron::Shutdown() 
{
    //TODO Auto-generated method stub
    if( active )
    {
		CConnectionScheduler::GetInstance() -> Shutdown();
		CMessageAllocator   ::GetInstance() -> Shutdown();

        active = false;
    }
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void electron::CElectron::Destruct() 
{
    //TODO Auto-generated method stub
	if( active == false )
	{
		// Detach allocator
        CObjectPtr allocator = CElectronAllocator::GetInstance();
		CInstanceFactory::GetInstance() -> Detach( allocator );
		allocator = NULL;

		CConnectionScheduler::DeleteInstance();
		CMessageAllocator   ::DeleteInstance();
		CElectronAllocator  ::DeleteInstance();
	}
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CElectron::IsActive() 
{
    //TODO Auto-generated method stub
    return active;
}
