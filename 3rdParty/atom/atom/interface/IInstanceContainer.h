#ifndef IINSTANCECONTAINER_H
#define IINSTANCECONTAINER_H
#include "IEmbedInterface.h"
#include "../utility/tool/CObjectPtr.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{


    
    class IInstanceContainer : public IEmbedInterface
    {




        public:

            virtual bool Insert(CObjectPtr & instance) = 0; 



            virtual CObjectPtr Obtain(U64 instance_name) = 0; 



            virtual void Obtain(CU64Array & instances) = 0; 



            virtual bool Inside(U64 instance_name) = 0; 



            virtual U64 Amount() = 0; 



            virtual bool Remove(U64 instance_name) = 0; 



            virtual void RemoveAll() = 0; 



    };  //end class IInstanceContainer


} //end namespace atom



#endif
