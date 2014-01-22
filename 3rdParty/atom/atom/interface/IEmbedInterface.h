#ifndef IEMBEDINTERFACE_H
#define IEMBEDINTERFACE_H
#include "IReferencedInterface.h"
#include "IInterface.h"



namespace atom
{



     class IEmbedInterface : public IReferencedInterface
     {




         public:

             virtual void SetNest(IInterface * nest) = 0; 



     };  //end class IEmbedInterface


}//end namespace atom


#endif
