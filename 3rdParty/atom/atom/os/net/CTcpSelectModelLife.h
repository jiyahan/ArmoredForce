#ifndef CTCPSELECTMODELLIFE_H
#define CTCPSELECTMODELLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpSelectModelLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CTcpSelectModelLife(); 



			virtual ~CTcpSelectModelLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CTcpSelectModelLife



} //end namespace atom



#endif
