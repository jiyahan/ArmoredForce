#ifndef IMAINTAINABLE_H
#define IMAINTAINABLE_H
#include "IEmbedInterface.h"



namespace atom
{



     class IMaintainable : public IEmbedInterface
     {




         public:

             virtual U64 OnMaintenance(U64 now) = 0; 



     };  //end class IMaintainable


}//end namespace atom


#endif
