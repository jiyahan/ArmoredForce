#ifndef CXMLELEMENT_H
#define CXMLELEMENT_H
#include "../../pattern/object/CReferencedObject.h"
#include "CXmlElementNode.h"
#include "CXmlElementLife.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CXmlElement : public CReferencedObject
	{


		private:


			CXmlElementNode node;



			CXmlElementLife life;




		public:

			CXmlElement(); 



			virtual ~CXmlElement(); 



			virtual const char * ToString(); 



			virtual IInterface * QueryInterface(U32 iid); 



	};  //end class CXmlElement



} //end namespace atom



#endif
