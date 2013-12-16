#ifndef CCODEPAGE_H
#define CCODEPAGE_H
//Begin section for file CCodePage.h
//TODO: Add definitions that you want preserved
//End section for file CCodePage.h
#include "CCodePageSingletonBind.h"
#include "CCodePageBind.h"
#include "../thread/CCriticalSection.h"



namespace atom
 {



     //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
     class CCodePage : public CCodePageSingletonBind
     {

         //Begin section for atom::CCodePage
         //TODO: Add attributes that you want preserved
         //End section for atom::CCodePage

         private:


             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             CCodePageBind related;



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             CCriticalSection section;




         public:

             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             CCodePage(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             ~CCodePage(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             bool Initiate(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             void Shutdown(); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             I32 CodePage(const char * value); 



             //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
             const char * GetLocal(); 



     };  //end class CCodePage


 }//end namespace atom


#endif
