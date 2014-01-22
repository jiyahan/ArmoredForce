#ifndef CIOCPBUFFER_H
#define CIOCPBUFFER_H
#include "../../Common.h"



namespace atom
{



	#ifdef _WIN32
	typedef WSABUF CIocpBuffer;
	#endif



} //end namespace atom



#endif
