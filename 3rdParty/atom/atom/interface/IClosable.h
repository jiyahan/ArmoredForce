#ifndef ICLOSABLE_H
#define ICLOSABLE_H
#include "IEmbedInterface.h"



namespace atom
{



     class IClosable : public IEmbedInterface
     {




         public:

             virtual void Close() = 0; 



     };  //end class IClosable


}//end namespace atom


#endif
