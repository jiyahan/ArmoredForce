#ifndef TAGFLOWSTATISTICS_H
#define TAGFLOWSTATISTICS_H
#include "../Common.h"



namespace electron
{



    struct tagFlowStatistics
    {




        public:


            U64 send_bytes;



            U64 send_frame;



            U64 read_bytes;



            U64 read_frame;



            inline tagFlowStatistics() : 
            send_bytes(0),send_frame(0),read_bytes(0),read_frame(0)
            {
            }



            inline ~tagFlowStatistics()
            {
            }



    };  //end struct tagFlowStatistics



} //end namespace electron



#endif
