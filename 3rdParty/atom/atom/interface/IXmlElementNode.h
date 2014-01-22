#ifndef IXMLELEMENTNODE_H
#define IXMLELEMENTNODE_H
#include "IEmbedInterface.h"
#include "../utility/xml/CDefinedXmlNode.h"



namespace atom
{



	class CXmlElementPtr;



	class IXmlElementNode : public IEmbedInterface
	{




		public:

			virtual bool Initiate(U64 parent, CDefinedXmlNode * node) = 0; 



			virtual void Shutdown() = 0; 



			virtual bool Append(const char * tag_name) = 0; 



			virtual bool Append(const char * tag_name, CXmlElementPtr & child) = 0; 



			virtual bool Remove(CXmlElementPtr & child) = 0; 



			virtual CXmlElementPtr Search(const char * tag_name, bool recursive=true) = 0; 



			virtual CXmlElementPtr Next(const char * tag_name) = 0; 



			virtual CDefinedXmlNode * Node() = 0; 



			virtual const char * GetName() = 0; 



			virtual const char * GetText() = 0; 



			virtual void SetText(const char * value) = 0; 



			virtual const char * StrAttribute(const char * name) = 0; 



			virtual I64 IntAttribute(const char * name) = 0; 



			virtual double FltAttribute(const char * name) = 0; 



			virtual bool SetAttribute(const char * name, const char * value) = 0; 



			virtual bool SetAttribute(const char * name, I64 value) = 0; 



			virtual bool SetAttribute(const char * name, double value) = 0; 



	};  //end class IXmlElementNode



} //end namespace atom



#endif
