#include "CElectron.h"


bool electron::CElectron::active = false;

void electron::CElectron::Presetup() 
{
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

bool electron::CElectron::Initiate(U32 thread_amount) 
{
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

bool electron::CElectron::Shutdown() 
{
    if( active )
    {
		CConnectionScheduler::GetInstance() -> Shutdown();
		CMessageAllocator   ::GetInstance() -> Shutdown();

        active = false;
    }
    return true;
}

void electron::CElectron::Destruct() 
{
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

bool electron::CElectron::IsActive() 
{
    return active;
}
