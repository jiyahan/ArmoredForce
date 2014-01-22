#ifndef CAPPLELIBRARY_H
#define CAPPLELIBRARY_H
#include "../../utility/stl/a_string.h"



namespace atom
{



	class CAppleLibrary
	{


		private:


			void * handle;



			a_string locate;




		public:

			CAppleLibrary(); 



			virtual ~CAppleLibrary(); 



			virtual bool Open(const char * file); 



			virtual bool Open(const wchar_t * file); 



			virtual void * GetFunction(const char * name); 



			virtual bool Close(); 



            // return utf8 charset as default;
			virtual a_string GetPath(); 



	};  //end class CAppleLibrary



} //end namespace atom



#endif
