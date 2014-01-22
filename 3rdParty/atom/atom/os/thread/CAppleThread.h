#ifndef CAPPLETHREAD_H
#define CAPPLETHREAD_H
#include "CSignal.h"
#include "CCriticalSection.h"
#include "../../enumeration/THREAD_PRIORITY.h"



namespace atom
{
	


	class CAppleThread
	{


		private:



            #ifdef __APPLE__
            pthread_t handle;
            #endif

			

			std::string thread;



			CSignal signal;



			CCriticalSection region;




		public:

			explicit CAppleThread(const char * name); 



			virtual ~CAppleThread(); 



			const char * GetName(); 



            void CloseNotify();



			virtual bool Begin(U08 priority = TP_NORMAL); 



			virtual bool Close(U64 timeout); 



			virtual bool OnThreadBegin(); 



			virtual bool OnThreadClose(); 



			virtual U32 Run(); 



			static void Sleep(U64 time); 



			static U64 GetCurrentThreadID(); 



	};  //end class CAppleThread



} //end namespace atom



#endif
