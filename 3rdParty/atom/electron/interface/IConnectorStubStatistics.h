#ifndef ICONNECTORSTUBSTATISTICS_H
#define ICONNECTORSTUBSTATISTICS_H
#include "../Common.h"
#include "../stub/tagFlowStatistics.h"



namespace electron
{



    class IConnectorStubStatistics : public IEmbedInterface
    {




        public:

            virtual void OnReadFrame(U64 origin, U64 reduce) = 0; 



            virtual void OnSendFrame(U64 origin, U64 reduce) = 0; 



            virtual void OnLongFrame(U64 value) = 0; 



            virtual void GetStatistics(U64 & largest, tagFlowStatistics & plain, tagFlowStatistics & final) = 0; 



            virtual void Reset() = 0; 



    };  //end class IConnectorStubStatistics



} //end namespace electron



#endif
