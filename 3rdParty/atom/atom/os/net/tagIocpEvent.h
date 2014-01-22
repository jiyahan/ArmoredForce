#ifndef TAGIOCPEVENT_H
#define TAGIOCPEVENT_H
#include "tagIocpOperation.h"



namespace atom
{



	struct tagIocpEvent
	{




		public:


			#ifdef _WIN32
			ULONG_PTR object;



			DWORD length;



			bool losted;



			tagIocpOperation * packet;
			#endif



			tagIocpEvent(); 



			void Reset(); 



	};  //end struct tagIocpEvent



} //end namespace atom



#endif
