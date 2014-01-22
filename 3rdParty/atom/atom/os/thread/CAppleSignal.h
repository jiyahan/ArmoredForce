#ifndef CAPPLESIGNAL_H
#define CAPPLESIGNAL_H
#include "../../Common.h"


namespace atom
{



	class CAppleSignal
	{


		private:


			bool state;



            #ifdef __APPLE__
            pthread_mutex_t region;



            pthread_cond_t  signal;
            #endif



		public:

			CAppleSignal(); 



			explicit CAppleSignal(const char * name); 



			~CAppleSignal(); 



			bool Reset(); 



			bool Awake(); 



			bool Await(U64 timeout); 



	};  //end class CAppleSignal



} //end namespace atom



#endif
