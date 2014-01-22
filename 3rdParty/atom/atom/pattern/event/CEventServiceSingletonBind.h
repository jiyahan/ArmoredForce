#ifndef CEVENTSERVICESINGLETONBIND_H
#define CEVENTSERVICESINGLETONBIND_H
#include "../singleton/CSingleton.h"



namespace atom
{
	


	class CEventService;
	typedef CSingleton<CEventService> CEventServiceSingletonBind;



} //end namespace atom



#endif
