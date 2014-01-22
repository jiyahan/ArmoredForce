#ifndef TAGEVENT_H
#define TAGEVENT_H
#include "../../utility/stl/a_string.h"
#include "../../utility/variant/CVariant.h"



namespace atom
{
	


	struct tagEvent
	{




		public:


			//<p>event type</p>
			U32 handle;



			//<p>event append data</p>
			CVariant append;



			//<p>source instance</p>
			U64 source;



			//<p>event target, empty means send to all.</p>
			a_string target;



			//<p>event description</p>
			a_string record;



			tagEvent(); 



			tagEvent(const tagEvent & value); 



			virtual ~tagEvent(); 



			tagEvent & operator=(const tagEvent & value); 



	};  //end struct tagEvent



} //end namespace atom



#endif
