#ifndef IFLUSHDEVICE_H
#define IFLUSHDEVICE_H
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     class IFlushDevice : public IEmbedInterface
     {




         public:

             virtual bool OnFlush(CMemory & value) = 0; 



     };  //end class IFlushDevice


}//end namespace atom


#endif
