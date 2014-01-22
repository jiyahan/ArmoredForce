#ifndef CCODEPAGESINGLETONBIND_H
#define CCODEPAGESINGLETONBIND_H
#include "../../pattern/singleton/CSingleton.h"



namespace atom
{

    class CCodePage;
    typedef CSingleton<CCodePage> CCodePageSingletonBind;

}//end namespace atom


#endif
