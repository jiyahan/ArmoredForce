#ifndef CIMPORTER_H
#define CIMPORTER_H
#include "../../interface/IInterface.h"
#include "../memory/CImportStream.h"



namespace atom
{



    class CImporter : public IInterface
    {


        private:


            CImportStream stream;




        public:

            CImporter(); 



            virtual ~CImporter(); 



            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CImporter


}//end namespace atom


#endif
