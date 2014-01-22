#ifndef IXMLDOCUMENTNODE_H
#define IXMLDOCUMENTNODE_H
#include "IXmlElementNode.h"
#include "../os/memory/CMemory.h"



namespace atom
{



	class IXmlDocumentNode : public IXmlElementNode
	{




		public:

			virtual bool Load(const char * file) = 0; 



			virtual bool Load(CMemory & data) = 0; 



			virtual bool Save(const char * file) = 0; 



			virtual bool Save(CMemory & data) = 0; 



			virtual void SetDeclaration(const char * version, const char * encoding) = 0; 



	};  //end class IXmlDocumentNode



} //end namespace atom



#endif
