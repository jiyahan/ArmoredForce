#ifndef CMAINTAINERLIFE_H
#define CMAINTAINERLIFE_H
#include "../interface/IInstanceLife.h"
#include "../interface/IInterface.h"



namespace atom
{
	


	class CMaintainerLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CMaintainerLife(); 



			virtual ~CMaintainerLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CMaintainerLife



} //end namespace atom


	
#endif
