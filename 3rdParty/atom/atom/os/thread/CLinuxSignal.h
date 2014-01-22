#ifndef CLINUXSIGNAL_H
#define CLINUXSIGNAL_H
#include "../../Common.h"


namespace atom
{



    class CLinuxSignal
    {


        private:


            bool state;



            #ifdef __linux            
            pthread_mutex_t region;



            pthread_cond_t  signal;
            #endif



        public:

            CLinuxSignal(); 



            explicit CLinuxSignal(const char * name); 



            ~CLinuxSignal(); 



            bool Reset(); 



            bool Awake(); 



            bool Await(U64 timeout); 



    };  //end class CLinuxSignal


}//end namespace atom


#endif
