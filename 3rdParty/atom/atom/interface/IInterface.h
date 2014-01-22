#ifndef IINTERFACE_H
#define IINTERFACE_H
#include "../Common.h"


namespace atom
{



    class IInterface
    {




        public:

            virtual IInterface * QueryInterface(U32 iid) = 0; 



    };  //end class IInterface


}//end namespace atom


#endif
