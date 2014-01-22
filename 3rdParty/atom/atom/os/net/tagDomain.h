#ifndef TAGDOMAIN_H
#define TAGDOMAIN_H
#include "../../utility/stl/a_string.h"



namespace atom
{



	struct tagDomain
	{




		public:


			a_string host;



			U16 port;



			tagDomain(); 



			tagDomain(const tagDomain & value); 



			virtual ~tagDomain(); 



			tagDomain & operator=(const tagDomain & value); 



	};  //end struct tagDomain



} //end namespace atom



#endif
