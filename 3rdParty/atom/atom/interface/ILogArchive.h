#ifndef ILOGARCHIVE_H
#define ILOGARCHIVE_H
#include "IEmbedInterface.h"


namespace atom
{



    class ILogArchive : public IEmbedInterface
    {




        public:

            virtual void Append(const char * value) = 0; 



            virtual void Finish(U08 level) = 0; 



    };  //end class ILogArchive



} //end namespace atom



#endif
