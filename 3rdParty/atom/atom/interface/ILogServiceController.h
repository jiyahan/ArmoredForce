#ifndef ILOGSERVICECONTROLLER_H
#define ILOGSERVICECONTROLLER_H
#include "IEmbedInterface.h"
#include "IInterface.h"



namespace atom
{



    class ILogServiceController : public IEmbedInterface
    {




        public:

            virtual void Setup(U08 display_level, IInterface * output) = 0; 



            virtual void Clear() = 0; 



            virtual void Write(U08 level, const char * log) = 0; 



            virtual void Flush() = 0; 



    };  //end class ILogServiceController



} //end namespace atom



#endif
