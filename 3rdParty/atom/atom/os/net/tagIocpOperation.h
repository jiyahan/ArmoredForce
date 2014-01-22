#ifndef TAGIOCPOPERATION_H
#define TAGIOCPOPERATION_H
#include "CIocpOverlap.h"
#include "CIocpBuffer.h"
#include "../memory/CMemory.h"
#include "../../utility/tool/CObjectPtr.h"



namespace atom
{



	struct tagIocpOperation
	{


		private:


			#ifdef _WIN32
			CObjectPtr ob;
			#endif



		public:


			#ifdef _WIN32
			U08 op;



			SOCKET hs;



			CIocpOverlap ol;



			CIocpBuffer wb;



			CMemory mb;
			#endif



			tagIocpOperation(); 



			~tagIocpOperation(); 



			void Reset(); 



			bool Attach(CObjectPtr & object); 



			void Detach(); 



			U64 GetObjectName(); 



			CObjectPtr GetObject(); 



	};  //end struct tagIocpOperation



} //end namespace atom



#endif
