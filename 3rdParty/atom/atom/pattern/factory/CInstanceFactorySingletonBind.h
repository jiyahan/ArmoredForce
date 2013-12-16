#ifndef CINSTANCEFACTORYSINGLETONBIND_H
#define CINSTANCEFACTORYSINGLETONBIND_H
//Begin section for file CInstanceFactorySingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CInstanceFactorySingletonBind.h
#include "../singleton/CSingleton.h"



namespace atom
{
	

	class CInstanceFactory;
	typedef CSingleton<CInstanceFactory> CInstanceFactorySingletonBind;



} //end namespace atom



#endif
