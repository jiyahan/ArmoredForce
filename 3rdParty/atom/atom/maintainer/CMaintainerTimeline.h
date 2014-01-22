#ifndef CMAINTAINERTIMELINE_H
#define CMAINTAINERTIMELINE_H
#include "../interface/IMaintainerTimeline.h"
#include "../interface/IInterface.h"
#include "../utility/stl/CU64Array.h"
#include "CMaintainerTimelineBind.h"



namespace atom
{
    


    class CMaintainerTimeline : public IMaintainerTimeline
    {


        private:


            IInterface * nest;



            CMaintainerTimelineBind line;




        public:

            CMaintainerTimeline(); 



            virtual ~CMaintainerTimeline(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void Mark(U64 time, U64 instance); 



            virtual void Forward(U64 time, CU64Array & instances); 



    };  //end class CMaintainerTimeline



} //end namespace atom



#endif
