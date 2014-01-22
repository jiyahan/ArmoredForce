#ifndef TAGALLOCATOR_H
#define TAGALLOCATOR_H
#include "../../utility/tool/CObjectPtr.h"


namespace atom
{



	struct tagAllocator
	{


		public:


			U32 lower;



			U32 upper;



			CObjectPtr point;




		public:

			tagAllocator(); 



			virtual ~tagAllocator(); 



			void Clear(); 



	};  //end struct tagAllocator



} //end namespace atom



#endif
