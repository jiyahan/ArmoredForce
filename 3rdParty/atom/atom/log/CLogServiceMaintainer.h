#ifndef CLOGSERVICEMAINTAINER_H
#define CLOGSERVICEMAINTAINER_H
#include "../interface/IMaintainable.h"
#include "../interface/IInterface.h"



namespace atom
{



    class CLogServiceMaintainer : public IMaintainable
    {


        private:


            IInterface * nest;




        public:

            CLogServiceMaintainer(); 



            virtual ~CLogServiceMaintainer(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual U64 OnMaintenance(U64 now); 



    };  //end class CLogServiceMaintainer



} //end namespace atom



#endif
