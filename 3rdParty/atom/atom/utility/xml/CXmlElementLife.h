#ifndef CXMLELEMENTLIFE_H
#define CXMLELEMENTLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CXmlElementLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CXmlElementLife(); 



			virtual ~CXmlElementLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CXmlElementLife



} //end namespace atom



#endif
