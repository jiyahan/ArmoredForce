#ifndef ITRUNCATABLE_H
#define ITRUNCATABLE_H
#include "IEmbedInterface.h"



namespace atom
{



     class ITruncatable : public IEmbedInterface
     {




         public:

             virtual void Truncate() = 0; 



     };  //end class ITruncatable


}//end namespace atom


#endif
