#ifndef IFLUSHABLE_H
#define IFLUSHABLE_H
#include "IEmbedInterface.h"



namespace atom
{



     class IFlushable : public IEmbedInterface
     {




         public:

             virtual void Flush() = 0; 



     };  //end class IFlushable


}//end namespace atom


#endif
