#ifndef CMAINTAINERLISTENER_H
#define CMAINTAINERLISTENER_H
#include "../interface/IInstanceContainerListener.h"
#include "../interface/IInterface.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



    class CMaintainerListener : public IInstanceContainerListener
    {


        private:


            IInterface * nest;




        public:

            CMaintainerListener(); 



            virtual ~CMaintainerListener(); 



            virtual int IncRef(); 



            virtual int DecRef(); 



            virtual int GetRef(); 



            virtual IInterface * QueryInterface(U32 iid); 



            virtual void SetNest(IInterface * nest); 



            virtual void OnInsertInstance(CObjectPtr & instance); 



            virtual void OnRemoveInstance(CObjectPtr & instance); 



    };  //end class CMaintainerListener



} //end namespace atom



#endif
