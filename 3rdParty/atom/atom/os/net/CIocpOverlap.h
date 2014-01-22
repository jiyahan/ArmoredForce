#ifndef CIOCPOVERLAP_H
#define CIOCPOVERLAP_H
#include "../../Common.h"



namespace atom
{



	#ifdef _WIN32
	typedef OVERLAPPED  CIocpOverlap;
	#endif



} //end namespace atom



#endif
