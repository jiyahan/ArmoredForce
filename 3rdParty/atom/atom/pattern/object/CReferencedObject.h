#ifndef CREFERENCEDOBJECT_H
#define CREFERENCEDOBJECT_H
#include "../../interface/IReferencedObject.h"
#include "../../os/thread/CReference.h"
#include "../../interface/IInterface.h"



namespace atom
{



	class CReferencedObject : public IReferencedObject
	{


		private:


			U32 type;



			U64 name;



			CReference lock;




		public:

			CReferencedObject(); 



			virtual ~CReferencedObject(); 



			virtual void SetName(U64 name); 



			virtual U64 GetName(); 



			virtual void SetType(U32 type); 



			virtual U32 GetType(); 



			virtual const char * ToString() = 0; 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid) = 0; 



	};  //end class CReferencedObject



} //end namespace atom



#endif
