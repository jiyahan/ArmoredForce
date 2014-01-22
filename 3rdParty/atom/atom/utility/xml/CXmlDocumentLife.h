#ifndef CXMLDOCUMENTLIFE_H
#define CXMLDOCUMENTLIFE_H
#include "../../interface/IInstanceLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CXmlDocumentLife : public IInstanceLife
	{


		private:


			IInterface * nest;




		public:

			CXmlDocumentLife(); 



			virtual ~CXmlDocumentLife(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(); 



			virtual bool Shutdown(); 



	};  //end class CXmlDocumentLife



} //end namespace atom



#endif
