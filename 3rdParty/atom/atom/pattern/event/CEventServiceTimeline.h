#ifndef CEVENTSERVICETIMELINE_H
#define CEVENTSERVICETIMELINE_H
#include "../../interface/IEventServiceTimeline.h"
#include "../../interface/IInterface.h"
#include "CEventServiceTimelineBind.h"
#include "../../utility/stl/CU64Array.h"



namespace atom
{



	class CEventServiceTimeline : public IEventServiceTimeline
	{


		private:


			IInterface * nest;



			CEventServiceTimelineBind line;




		public:

			CEventServiceTimeline(); 



			virtual ~CEventServiceTimeline(); 



			virtual int IncRef(); 



			virtual int DecRef(); 



			virtual int GetRef(); 



			virtual IInterface * QueryInterface(U32 iid); 



			virtual void SetNest(IInterface * nest); 



			virtual void Mark(U64 time, U64 instance); 



			virtual void Forward(U64 time, CU64Array & instances); 



	};  //end class CEventServiceTimeline



} //end namespace atom



#endif
