#include "CSystemInformation.h"


U32 atom::CSystemInformation::GetProcessorCount()  
{
	U32 result(0);

	#if defined(_WIN32)
	SYSTEM_INFO si;
	GetSystemInfo( & si );
	result = static_cast<U32>( si.dwNumberOfProcessors );
	#endif

	#if defined(__linux) || defined(__APPLE__)
	result = static_cast<U32>( sysconf(_SC_NPROCESSORS_CONF) );
	#endif

	return result;
}

U64 atom::CSystemInformation::GetPhysicalMemorySize()  
{
	U64 result(0);

	#if defined(_WIN32)
	MEMORYSTATUSEX status;
	status.dwLength = sizeof( status );
	
	GlobalMemoryStatusEx( & status );
	result = static_cast<U64>( status.ullTotalPhys );
	#endif

	#if defined(__linux)
	result = static_cast<U64>( sysconf(_SC_PAGESIZE) * sysconf(_SC_PHYS_PAGES) );
	#endif

    #if defined(__APPLE__)
    int command[] = { CTL_HW, HW_MEMSIZE };
    U64 output(0); size_t length = sizeof( output );
    if( sysctl( command, sizeof(command) / sizeof(int), & output, & length, NULL, 0 ) == 0 ) {
        result = output;
    }
    #endif

	return result;
}

U64 atom::CSystemInformation::GetPhysicalMemoryFree()  
{
	U64 result(0);

	#if defined(_WIN32)
	MEMORYSTATUSEX status;
	status.dwLength = sizeof( status );
	
	GlobalMemoryStatusEx( & status );
	result = static_cast<U64>( status.ullAvailPhys );
	#endif

	#if defined(__linux)
	result = static_cast<U64>( sysconf(_SC_PAGESIZE) * sysconf(_SC_AVPHYS_PAGES) );
	#endif

    #if defined(__APPLE__)
    vm_statistics_data_t   host_info;
    mach_msg_type_number_t host_info_outCnt;

    host_info_outCnt = HOST_VM_INFO_COUNT;
    if( host_statistics( mach_host_self(), HOST_VM_INFO, (host_info_t) 
        & host_info, & host_info_outCnt ) == KERN_SUCCESS ) 
    {
        // on Mac OSX 10.4 (Tiger), there is no speculative page counting
        // VM_PAGE_QUERY_PAGE_SPECULATIVE is defined in 10.5's mach/vm_statistics.h (included in mach.h)
        result = sysconf( _SC_PAGESIZE );

        #if defined( VM_PAGE_QUERY_PAGE_SPECULATIVE )
        result = result * ( host_info.free_count - host_info.speculative_count );
        #else
        result = result * host_info.free_count;
        #endif
    }
    #endif
	return result;
}
