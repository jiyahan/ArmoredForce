#include "CAtom.h"


bool atom::CAtom::active = false;

void atom::CAtom::Presetup() 
{
	if( active == false )
	{
        #if defined(__APPLE__) || defined(__linux)
        // Locate must be setup correctly, that may affect the character 
        // set convertion.
        setlocale( LC_ALL, DEFAULT_LOCATE );
        #endif
        
		CMemoryScheduler  ::CreateInstance();
		CCodePage         ::CreateInstance();
		CMaintainer       ::CreateInstance();
        CLogService       ::CreateInstance();		
        CInstanceFactory  ::CreateInstance();
		CAtomAllocator    ::CreateInstance();
		CInstanceLife     ::CreateInstance();
		CEventService     ::CreateInstance();
		CTcpNetworkService::CreateInstance();

		// Attach allocator
		CObjectPtr allocator = CAtomAllocator::GetInstance();
		CInstanceFactory::GetInstance() -> Attach( allocator );
	}
}

bool atom::CAtom::Initiate(size_t memory_pool) 
{
    bool result = false;
    if( active == false )
    {
        active = true;
        result = true;

        CCallStack::Initiate();

		#ifdef _WIN32
		WSADATA data;
		WORD version = MAKEWORD( 2, 0 );
		if( result && ( WSAStartup(version, &data) == 0 ) )
		{
			if( data.wVersion != version )
			{
				OutputDebugString( "Init Winsock 2.0 Failed!\n" );
				WSACleanup();
			}
		}
		#endif

		result &= 
        CMemoryScheduler  ::GetInstance() -> Initiate( memory_pool );
        result &= 
        CCodePage         ::GetInstance() -> Initiate();
        result &= 
        CMaintainer       ::GetInstance() -> Initiate();
        result &= 
        CLogService       ::GetInstance() -> Initiate();
        result &= 
        CInstanceFactory  ::GetInstance() -> Initiate();
		result &= 
		CInstanceLife     ::GetInstance() -> Initiate();
		result &= 
		CEventService     ::GetInstance() -> Initiate();
		result &=
		CTcpNetworkService::GetInstance() -> Initiate();
    }
    return result;
}

bool atom::CAtom::Shutdown() 
{
    if( active )
    {
		CTcpNetworkService::GetInstance() -> Shutdown();
		CEventService     ::GetInstance() -> Shutdown();
		CInstanceLife     ::GetInstance() -> Shutdown();
        CInstanceFactory  ::GetInstance() -> Shutdown();
        CLogService       ::GetInstance() -> Shutdown();
		CMaintainer       ::GetInstance() -> Shutdown();
        CCodePage         ::GetInstance() -> Shutdown();
        CMemoryScheduler  ::GetInstance() -> Shutdown();

		#ifdef _WIN32
		WSACleanup();
		#endif

        CCallStack::Shutdown();
        active = false;
    }
    return true;
}

void atom::CAtom::Destruct() 
{
	if( active == false )
	{
		// Detach allocator
		CObjectPtr allocator = CAtomAllocator::GetInstance();
		CInstanceFactory::GetInstance() -> Detach( allocator );
		allocator = NULL;

		CTcpNetworkService::DeleteInstance();
		CEventService     ::DeleteInstance();
        CInstanceLife     ::DeleteInstance();
		CAtomAllocator    ::DeleteInstance();
        CInstanceFactory  ::DeleteInstance();
        CLogService       ::DeleteInstance();	
        CMaintainer       ::DeleteInstance();
        CCodePage         ::DeleteInstance();
		CMemoryScheduler  ::DeleteInstance();
	}
}

bool atom::CAtom::IsActive() 
{
    return active;
}
