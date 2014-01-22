#ifndef CCODEPAGE_H
#define CCODEPAGE_H
#include "CCodePageSingletonBind.h"
#include "CCodePageBind.h"
#include "../thread/CCriticalSection.h"



namespace atom
 {



     class CCodePage : public CCodePageSingletonBind
     {


         private:


             CCodePageBind related;



             CCriticalSection section;




         public:

             CCodePage(); 



             ~CCodePage(); 



             bool Initiate(); 



             void Shutdown(); 



             I32 CodePage(const char * value); 



             const char * GetLocal(); 



     };  //end class CCodePage


 }//end namespace atom


#endif
