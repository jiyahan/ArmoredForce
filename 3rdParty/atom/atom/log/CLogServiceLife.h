#ifndef CLOGSERVICELIFE_H
#define CLOGSERVICELIFE_H
#include "../interface/IInstanceLife.h"
#include "../interface/IInterface.h"



namespace atom
{



    class CLogServiceLife : public IInstanceLife
    {


        private:


            IInterface * nest;




        public:

            CLogServiceLife(); 



            virtual ~CLogServiceLife(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual bool Initiate(); 



            virtual bool Shutdown(); 



    };  //end class CLogServiceLife



} //end namespace atom



#endif
