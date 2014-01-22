#ifndef IINSTANCECONTAINERLISTENER_H
#define IINSTANCECONTAINERLISTENER_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



    class IInstanceContainerListener : public IEmbedInterface
    {




        public:

            virtual void OnInsertInstance(CObjectPtr & instance) = 0; 



            virtual void OnRemoveInstance(CObjectPtr & instance) = 0; 



    };  //end class IInstanceContainerListener



} //end namespace atom



#endif
