#ifndef CKQUEUEEVENT_H
#define CKQUEUEEVENT_H
#include "../../Common.h"



namespace atom
{



	#ifdef __APPLE__
	typedef struct kevent  CKQueueEvent ;
	#endif



} //end namespace atom



#endif
