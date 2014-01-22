#ifndef CSINGLETON_H
#define CSINGLETON_H
#include "../../Common.h"


namespace atom
{



    template <class T>
    class CSingleton
    {


        private:


            static T * singleton;




        public:


            inline static bool  CreateInstance()
            {
                if( singleton == NULL ) {
                    singleton = new T;
                }
                return singleton != NULL;
            }


            inline static void  DeleteInstance()
            {
                SAFE_DELETE( singleton );
            }


            inline static T *  GetInstance()
            {
                #ifdef _DEBUG
                if( singleton == NULL ) {
                    throw std::bad_alloc();
                }
                #endif
                return singleton;
            }

    };  //end class CSingleton


}//end namespace atom



template <class T> T * atom::CSingleton<T>::singleton = NULL;


#endif
