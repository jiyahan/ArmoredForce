#ifndef IMAINTAINERTIMELINE_H
#define IMAINTAINERTIMELINE_H
//Begin section for file IMaintainerTimeline.h
//TODO: Add definitions that you want preserved
//End section for file IMaintainerTimeline.h
#include "IEmbedInterface.h"
#include "../utility/stl/CU64Array.h"



namespace atom
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class IMaintainerTimeline : public IEmbedInterface
    {

        //Begin section for atom::IMaintainerTimeline
        //TODO: Add attributes that you want preserved
        //End section for atom::IMaintainerTimeline



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Mark(U64 time, U64 instance) = 0; 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Forward(U64 time, CU64Array & instances) = 0; 



    };  //end class IMaintainerTimeline



} //end namespace atom



#endif
