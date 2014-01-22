#ifndef IMULTITHREADCONTROL_H
#define IMULTITHREADCONTROL_H
#include "IThreadControl.h"



namespace atom
{



    class IMultiThreadControl : public IThreadControl
    {




        public:

            virtual bool OnBegin(U32 index) = 0; 



            virtual bool OnClose(U32 index) = 0; 



            virtual void OnAwake(U32 index) = 0; 



            virtual void SetThreadAmount(U32 index) = 0; 
            


            virtual U32 GetThreadAmount() = 0; 



    };  //end class IMultiThreadControl



} //end namespace atom



#endif
