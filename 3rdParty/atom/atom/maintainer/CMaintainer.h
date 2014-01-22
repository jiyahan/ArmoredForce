#ifndef CMAINTAINER_H
#define CMAINTAINER_H
#include "../interface/IInterface.h"
#include "CMaintainerLife.h"
#include "CMaintainerSingletonBind.h"
#include "CMaintainerThread.h"
#include "CMaintainerListener.h"
#include "CMaintainerTimeline.h"
#include "../pattern/container/CInstanceContainer.h"
#include "../utility/tool/CObjectPtr.h"



namespace atom
{



    class CMaintainer : public IInterface, public CMaintainerSingletonBind
    {


        private:


            CMaintainerThread thread;



            CInstanceContainer container;



            CMaintainerListener listener;



            CMaintainerTimeline timeline;



            CMaintainerLife life;



        public:

            CMaintainer(); 



            virtual ~CMaintainer(); 



            virtual IInterface * QueryInterface(U32 iid); 



            bool Attach(CObjectPtr & value); 



            void Detach(CObjectPtr & value); 



            void Detach(U64 instance_name); 



            bool Initiate(); 



            bool Shutdown(); 



    };  //end class CMaintainer



} //end namespace atom



#endif
