#ifndef CSYSTEMINFORMATION_H
#define CSYSTEMINFORMATION_H
#include "../../Common.h"



namespace atom
{



	class CSystemInformation
	{




		public:

			static U32 GetProcessorCount(); 



			static U64 GetPhysicalMemorySize(); 



			static U64 GetPhysicalMemoryFree(); 



	};  //end class CSystemInformation



} //end namespace atom



#endif
