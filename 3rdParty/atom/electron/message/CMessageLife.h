#ifndef CMESSAGELIFE_H
#define CMESSAGELIFE_H
#include "../Common.h"



namespace electron
{



    class CMessageLife : public IInstanceLife
    {


        private:


            IInterface * nest;



			#ifdef _SHIPPING_
			IReferencedInterface * cast;
			#endif




        public:

            CMessageLife(); 



            virtual ~CMessageLife(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Initiate(); 



            virtual bool Shutdown(); 



    };  //end class CMessageLife



} //end namespace electron



#endif
