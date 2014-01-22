#ifndef CIOPORTER_H
#define CIOPORTER_H
#include "../../interface/IInterface.h"
#include "../memory/CStream.h"



namespace atom
{



    class CIOPorter : public IInterface
    {


        private:


            CStream stream;




        public:

            CIOPorter(); 



            virtual ~CIOPorter(); 



            IInterface * QueryInterface(U32 iid); 



    };  //end class CIOPorter


}//end namespace atom


#endif
