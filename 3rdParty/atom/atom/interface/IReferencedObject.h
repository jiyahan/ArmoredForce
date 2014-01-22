#ifndef IREFERENCEDOBJECT_H
#define IREFERENCEDOBJECT_H
#include "IReferencedInterface.h"



namespace atom
{



     class IReferencedObject : public IReferencedInterface
     {




         public:

             virtual void SetName(U64 name) = 0; 



             virtual U64 GetName() = 0; 



             virtual void SetType(U32 type) = 0; 



             virtual U32 GetType() = 0; 



             virtual const char * ToString() = 0; 



     };  //end class IReferencedObject


}//end namespace atom


#endif
