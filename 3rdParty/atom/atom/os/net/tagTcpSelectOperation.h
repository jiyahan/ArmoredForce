#ifndef TAGTCPSELECTOPERATION_H
#define TAGTCPSELECTOPERATION_H
#include "../memory/CMemory.h"
#include "../../utility/stl/allocator.h"



namespace atom
{



	struct tagTcpSelectOperation
	{


		public:


			typedef std::set<tagTcpSelectOperation, less<tagTcpSelectOperation>, atom_allocator<tagTcpSelectOperation> >  CTcpSelectOperationBind ;



		public:


			SOCKET socket;



			CMemory memory;



			size_t offset;



			size_t length;



			//<p>target connector</p>
			U64 target;



			//<p>operation serial no.</p>
			I32 serial;



			tagTcpSelectOperation(); 



			tagTcpSelectOperation(const tagTcpSelectOperation & value); 



			~tagTcpSelectOperation(); 



			tagTcpSelectOperation & operator=(const tagTcpSelectOperation & value); 



			bool operator<(const tagTcpSelectOperation & value)const ; 



	};  //end struct tagTcpSelectOperation



} //end namespace atom



#endif
