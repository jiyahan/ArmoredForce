#ifndef ISWAPPABLE_H
#define ISWAPPABLE_H
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
{



     class ISwappable : public IEmbedInterface
     {




         public:

             virtual bool Swap(CMemory & data) = 0; 



     };  //end class ISwappable


}//end namespace atom


#endif
