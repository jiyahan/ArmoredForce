#include "tagIocpEvent.h"


atom::tagIocpEvent::tagIocpEvent() 
#ifdef _WIN32
: object(0),length(0),losted(false),packet(NULL)
#endif
{
}
void atom::tagIocpEvent::Reset() 
{
	#ifdef _WIN32
	object = 0;
	length = 0;
	losted = false;
	packet = NULL;
	#endif
}
