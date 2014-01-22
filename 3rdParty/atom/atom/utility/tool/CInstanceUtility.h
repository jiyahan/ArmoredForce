#ifndef CINSTANCEUTILITY_H
#define CINSTANCEUTILITY_H
#include "../../interface/IInterface.h"
#include "CObjectPtr.h"



namespace atom
{



	class CInstanceUtility
	{




		public:

			static CObjectPtr CreateInstance(U32 type); 



			static CObjectPtr ObtainInstance(U64 name); 



			static bool InitiateInstance(CObjectPtr & value); 



			static bool ShutdownInstance(CObjectPtr & value); 



			static U64 GetInstanceName(IInterface * value); 



			static U32 GetInstanceType(IInterface * value); 



			static const char * GetInstanceDesc(IInterface * value); 



            static CObjectPtr MakeObject(IInterface * nest); 



	};  //end class CInstanceUtility



} //end namespace atom



#endif
