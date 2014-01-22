#ifndef TAGFRAME_H
#define TAGFRAME_H
#include "../Common.h"



namespace electron
{

    

    struct tagFrame
    {


        public:


            struct tagFrameLength
            {




                public:


                    //<p>plain data original length</p>
                    U64 origin;



                    //<p>crypto data length</p>
                    U64 crypto;



                    //<p>compressed crypto data length</p>
                    U64 reduce;



                    inline tagFrameLength() :
                    origin(0),crypto(0),reduce(0)
                    {
                    }



                    inline tagFrameLength(const tagFrame::tagFrameLength & value)
                    {
                        *this = value;
                    }



                    inline ~tagFrameLength()
                    {
                    }



                    inline tagFrame::tagFrameLength & operator=(const tagFrame::tagFrameLength & value)
                    {
                        origin = value.origin;
                        crypto = value.crypto;
                        reduce = value.reduce;
                        return( *this );
                    }



            };  //end struct tagFrameLength



            typedef std::vector<tagFrame, atom_allocator<tagFrame> >  CFrameArray ;



        public:


            //<p>data try to send</p>
            CMemory memory;



            //<p>plain data length</p>
            tagFrameLength length;



            //<p>plain data checksum</p>
            U16 verify;



            inline tagFrame() :
            verify(0)
            {
            }



            inline tagFrame(const tagFrame & value)
            {
                *this = value;
            }



            inline ~tagFrame()
            {
            }



            inline tagFrame & operator=(const tagFrame & value)
            {
                memory = value.memory;
                length = value.length;
                verify = value.verify;
                return( *this );
            }



    };  //end struct tagFrame



} //end namespace electron



#endif
