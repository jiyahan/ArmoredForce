#ifndef CEVENTSERVICESINGLETONBIND_H
#define CEVENTSERVICESINGLETONBIND_H
//Begin section for file CEventServiceSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CEventServiceSingletonBind.h
#include "../singleton/CSingleton.h"



namespace atom
{
	


	class CEventService;
	typedef CSingleton<CEventService> CEventServiceSingletonBind;



} //end namespace atom



#endif
