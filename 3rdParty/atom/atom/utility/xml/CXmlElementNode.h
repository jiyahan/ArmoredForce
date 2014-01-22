#ifndef CXMLELEMENTNODE_H
#define CXMLELEMENTNODE_H
#include "CDefinedXmlNode.h"
#include "../../interface/IXmlElementNode.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CXmlElementNode : public IXmlElementNode
	{


		private:


			IInterface * nest;



			CDefinedXmlNode * self;



			U64 node;




		public:

			CXmlElementNode(); 



			virtual ~CXmlElementNode(); 



			CDefinedXmlNode * Search(CDefinedXmlNode * parent, const char * tag_name, bool recursive); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual bool Initiate(U64 parent, CDefinedXmlNode * node); 



			virtual void Shutdown(); 



			virtual bool Append(const char * tag_name); 



			virtual bool Append(const char * tag_name, CXmlElementPtr & child); 



			virtual bool Remove(CXmlElementPtr & child); 



			virtual CXmlElementPtr Search(const char * tag_name, bool recursive=true); 



			virtual CXmlElementPtr Next(const char * tag_name); 



			virtual CDefinedXmlNode * Node(); 



			virtual const char * GetName(); 



			virtual const char * GetText(); 



			virtual void SetText(const char * value); 



			virtual const char * StrAttribute(const char * name); 



			virtual I64 IntAttribute(const char * name); 



			virtual double FltAttribute(const char * name); 



			virtual bool SetAttribute(const char * name, const char * value); 



			virtual bool SetAttribute(const char * name, I64 value); 



			virtual bool SetAttribute(const char * name, double value); 



	};  //end class CXmlElementNode



} //end namespace atom



#endif
