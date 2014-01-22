#ifndef TAGWRAPPER_H
#define TAGWRAPPER_H
#include "../../interface/IStream.h"
#include "../../interface/IImportStream.h"
#include "../../interface/IExportStream.h"



namespace atom
{



	union tagWrapper
	{




		public:


			void * u;



			IStream * s;



			IImportStream * i;



			IExportStream * e;



			tagWrapper(); 



			~tagWrapper(); 



			void Clear();



	};  //end union tagWrapper



} //end namespace atom



#endif
