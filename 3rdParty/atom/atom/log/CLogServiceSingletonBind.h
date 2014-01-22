#ifndef CLOGSERVICESINGLETONBIND_H
#define CLOGSERVICESINGLETONBIND_H
#include "../pattern/singleton/CSingleton.h"



namespace atom
{


    class CLogService;
    typedef CSingleton<CLogService> CLogServiceSingletonBind;



} //end namespace atom



#endif
