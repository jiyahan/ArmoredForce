#ifndef IASSIGNABLE_H
#define IASSIGNABLE_H
#include "IEmbedInterface.h"
#include "../os/memory/CMemory.h"



namespace atom
 {



     class IAssignable : public IEmbedInterface
     {




         public:

             virtual bool Assign(CMemory & data) = 0; 



     };  //end class IAssignable


 }//end namespace atom


#endif
