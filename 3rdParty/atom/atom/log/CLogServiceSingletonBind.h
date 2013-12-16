#ifndef CLOGSERVICESINGLETONBIND_H
#define CLOGSERVICESINGLETONBIND_H
//Begin section for file CLogServiceSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CLogServiceSingletonBind.h
#include "../pattern/singleton/CSingleton.h"



namespace atom
{


    class CLogService;
    typedef CSingleton<CLogService> CLogServiceSingletonBind;



} //end namespace atom



#endif
