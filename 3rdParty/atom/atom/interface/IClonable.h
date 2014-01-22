#ifndef ICLONABLE_H
#define ICLONABLE_H
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     class IClonable : public IEmbedInterface
     {




         public:

             virtual bool Clone(CMemory & data) = 0; 



     };  //end class IClonable


}//end namespace atom


#endif
