#ifndef CINSTANCEFACTORYSINGLETONBIND_H
#define CINSTANCEFACTORYSINGLETONBIND_H
#include "../singleton/CSingleton.h"



namespace atom
{
	

	class CInstanceFactory;
	typedef CSingleton<CInstanceFactory> CInstanceFactorySingletonBind;



} //end namespace atom



#endif
