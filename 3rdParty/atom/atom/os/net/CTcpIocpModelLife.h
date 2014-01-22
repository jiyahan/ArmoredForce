#ifndef CTCPIOCPMODELLIFE_H
#define CTCPIOCPMODELLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CTcpIocpModelLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CTcpIocpModelLife(); 



			virtual ~CTcpIocpModelLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CTcpIocpModelLife



} //end namespace atom



#endif
