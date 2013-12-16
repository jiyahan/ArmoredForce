#ifndef TAGFRAME_H
#define TAGFRAME_H
//Begin section for file tagFrame.h
//TODO: Add definitions that you want preserved
//End section for file tagFrame.h
#include "../Common.h"



namespace electron
{

    

    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    struct tagFrame
    {

        //Begin section for electron::tagFrame
        //TODO: Add attributes that you want preserved
        //End section for electron::tagFrame

        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            struct tagFrameLength
            {

                //Begin section for electron::tagFrame::tagFrameLength
                //TODO: Add attributes that you want preserved
                //End section for electron::tagFrame::tagFrameLength



                public:


                    //<p>plain data original length</p>
                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    U64 origin;



                    //<p>crypto data length</p>
                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    U64 crypto;



                    //<p>compressed crypto data length</p>
                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    U64 reduce;



                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    inline tagFrameLength() :
                    origin(0),crypto(0),reduce(0)
                    {
                        //TODO Auto-generated method stub
                    }



                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    inline tagFrameLength(const tagFrame::tagFrameLength & value)
                    {
                        //TODO Auto-generated method stub
                        *this = value;
                    }



                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    inline ~tagFrameLength()
                    {
                        //TODO Auto-generated method stub
                    }



                    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
                    inline tagFrame::tagFrameLength & operator=(const tagFrame::tagFrameLength & value)
                    {
                        //TODO Auto-generated method stub
                        origin = value.origin;
                        crypto = value.crypto;
                        reduce = value.reduce;
                        return( *this );
                    }



            };  //end struct tagFrameLength



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            typedef std::vector<tagFrame, atom_allocator<tagFrame> >  CFrameArray ;



        public:


            //<p>data try to send</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMemory memory;



            //<p>plain data length</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            tagFrameLength length;



            //<p>plain data checksum</p>
            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            U16 verify;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagFrame() :
            verify(0)
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagFrame(const tagFrame & value)
            {
                //TODO Auto-generated method stub
                *this = value;
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline ~tagFrame()
            {
                //TODO Auto-generated method stub
            }



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline tagFrame & operator=(const tagFrame & value)
            {
                //TODO Auto-generated method stub
                memory = value.memory;
                length = value.length;
                verify = value.verify;
                return( *this );
            }



    };  //end struct tagFrame



} //end namespace electron



#endif
