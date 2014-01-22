#ifndef IFILESTREAM_H
#define IFILESTREAM_H
#include "IStream.h"



namespace atom
{



    class IFileStream : public IStream
    {




        public:

            virtual bool Open() = 0; 



            virtual bool IsReadOnly() = 0; 



    };  //end class IFileStream


}//end namespace atom


#endif
