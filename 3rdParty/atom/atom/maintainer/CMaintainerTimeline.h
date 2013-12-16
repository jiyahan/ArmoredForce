#ifndef CMAINTAINERTIMELINE_H
#define CMAINTAINERTIMELINE_H
//Begin section for file CMaintainerTimeline.h
//TODO: Add definitions that you want preserved
//End section for file CMaintainerTimeline.h
#include "../interface/IMaintainerTimeline.h"
#include "../interface/IInterface.h"
#include "../utility/stl/CU64Array.h"
#include "CMaintainerTimelineBind.h"



namespace atom
{
    


    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CMaintainerTimeline : public IMaintainerTimeline
    {

        //Begin section for atom::CMaintainerTimeline
        //TODO: Add attributes that you want preserved
        //End section for atom::CMaintainerTimeline

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            IInterface * nest;



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerTimelineBind line;




        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            CMaintainerTimeline(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual ~CMaintainerTimeline(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int IncRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int DecRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual int GetRef(); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual IInterface * QueryInterface(U32 iid); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void SetNest(IInterface * nest); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Mark(U64 time, U64 instance); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            virtual void Forward(U64 time, CU64Array & instances); 



    };  //end class CMaintainerTimeline



} //end namespace atom



#endif
