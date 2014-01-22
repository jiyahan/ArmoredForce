#ifndef CXMLDOCUMENT_H
#define CXMLDOCUMENT_H
#include "../../pattern/object/CReferencedObject.h"
#include "CXmlDocumentLife.h"
#include "CXmlDocumentNode.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CXmlDocument : public CReferencedObject
	{


		private:


			CXmlDocumentLife life;



			CXmlDocumentNode node;




		public:

			CXmlDocument(); 



			virtual ~CXmlDocument(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CXmlDocument



} //end namespace atom



#endif
