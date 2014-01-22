#ifndef CEXPORTER_H
#define CEXPORTER_H
#include "../../interface/IInterface.h"
#include "../memory/CExportStream.h"




namespace atom
{



    class CExporter : public IInterface
    {


        private:


            CExportStream stream;




        public:

            CExporter(); 



            virtual ~CExporter(); 



            virtual IInterface * QueryInterface(U32 iid); 



    };  //end class CExporter


}//end namespace atom


#endif
