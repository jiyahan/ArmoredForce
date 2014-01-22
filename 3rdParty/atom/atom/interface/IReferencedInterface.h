#ifndef IREFERENCEDINTERFACE_H
#define IREFERENCEDINTERFACE_H
#include "IInterface.h"



namespace atom
{



     class IReferencedInterface : public IInterface
     {




         public:

             virtual int IncRef() = 0; 



             virtual int DecRef() = 0; 



             virtual int GetRef() = 0; 



     };  //end class IReferencedInterface


}//end namespace atom


#endif
