#ifndef CSINGLETON_H
#define CSINGLETON_H
//Begin section for file CSingleton.h
//TODO: Add definitions that you want preserved
//End section for file CSingleton.h
#include "../../Common.h"


namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    class CSingleton
    {

        //Begin section for atom::CSingleton
        //TODO: Add attributes that you want preserved
        //End section for atom::CSingleton

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            static T * singleton;




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static bool  CreateInstance()
            {
                //TODO Auto-generated method stub
                if( singleton == NULL ) {
                    singleton = new T;
                }
                return singleton != NULL;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static void  DeleteInstance()
            {
                //TODO Auto-generated method stub
                SAFE_DELETE( singleton );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static T *  GetInstance()
            {
                //TODO Auto-generated method stub
                #ifdef _DEBUG
                if( singleton == NULL ) {
                    throw std::bad_alloc();
                }
                #endif
                return singleton;
            }

    };  //end class CSingleton


}//end namespace atom



//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
template <class T> T * atom::CSingleton<T>::singleton = NULL;


#endif
