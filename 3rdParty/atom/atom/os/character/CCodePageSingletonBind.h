#ifndef CCODEPAGESINGLETONBIND_H
#define CCODEPAGESINGLETONBIND_H
//Begin section for file CCodePageSingletonBind.h
//TODO: Add definitions that you want preserved
//End section for file CCodePageSingletonBind.h
#include "../../pattern/singleton/CSingleton.h"



namespace atom
{

    class CCodePage;
    typedef CSingleton<CCodePage> CCodePageSingletonBind;

}//end namespace atom


#endif
