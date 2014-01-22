#ifndef CTCPSELECTMODELTHREAD_H
#define CTCPSELECTMODELTHREAD_H
#include "../../interface/IThreadControl.h"
#include "../thread/CThread.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpSelectModelThread : public IThreadControl, public CThread
	{


		private:


			IInterface * nest;




		public:

			CTcpSelectModelThread(); 



			virtual ~CTcpSelectModelThread(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool OnThreadBegin(); 



			virtual bool OnThreadClose(); 



			virtual U32 Run(); 



			virtual bool OnBegin(); 



			virtual bool OnClose(); 



			virtual void OnAwake(); 



	};  //end class CTcpSelectModelThread



} //end namespace atom



#endif
