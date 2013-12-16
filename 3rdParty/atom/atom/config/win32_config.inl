#ifdef  _WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1000)

	#pragma once
	#pragma comment( lib, "DbgHelp.lib" )
	#pragma comment( lib, "ws2_32.lib"  )
	#pragma comment( lib, "mswsock.lib" )
	#pragma comment( lib, "winmm.lib"   )
	#pragma comment( lib, "version.lib" )

	#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
	#endif

	#ifndef _SCL_SECURE_NO_WARNINGS
	#define _SCL_SECURE_NO_WARNINGS
	#endif

#endif

#if defined (_WIN32_WINNT) 
	#if _WIN32_WINNT < 0x0502
	#undef  _WIN32_WINNT
	#define _WIN32_WINNT 0x0502
	#endif
#else
	#define _WIN32_WINNT 0x0502
#endif 

#define IOCP_TH_RATIO   2
#define MAX_IOCP_HANDLE 32
#define MAX_IOCP_THREAD MAX_IOCP_HANDLE * IOCP_TH_RATIO

#endif 
