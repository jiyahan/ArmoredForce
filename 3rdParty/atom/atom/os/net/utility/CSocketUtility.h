#ifndef CSOCKETUTILITY_H
#define CSOCKETUTILITY_H
#include "../../../Common.h"
#include "../../../utility/tool/CObjectPtr.h"
#include "../../../utility/stl/a_string.h"



namespace atom
{



	class CSocketUtility
	{




		public:

			static U32 DomainToIPV4(const char * address); 



			static bool Open(CObjectPtr & object, const char * host, U16 port, U32 io_model);



			static void Shut(CObjectPtr & object);



			static a_string GetSelfAddress(CObjectPtr & object);



			static U16 GetSelfPort(CObjectPtr & object);



			static a_string GetPeerAddress(CObjectPtr & object);



			static U16 GetPeerPort(CObjectPtr & object);



	};  //end class CSocketUtility
	


} //end namespace atom



#endif
