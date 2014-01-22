#ifndef CINTERFACE_H
#define CINTERFACE_H
#include "../../Common.h"
#include "../../interface/IInterface.h"



namespace atom
{



    template <class T>
    class CInterface
    {


        private:


            T * segment;




        public:


            inline CInterface(): 
            segment(NULL)
            {
            }


            inline virtual ~CInterface()
            {
                if( segment )
                {
                    IReferencedInterface * refered = 
                        dynamic_cast<IReferencedInterface *>( segment );
                    SAFE_DECREF( refered );
                    segment = NULL;
                }
            }


            inline void Reset()
            {
                if( segment )
                {
                    IReferencedInterface * refered = 
                        dynamic_cast<IReferencedInterface *>( segment );
                    SAFE_DECREF( refered );
                    segment = NULL;
                }
            }


            inline bool  Mount(IInterface * unknow, U32 iid)
            {
                if( unknow && iid && segment == NULL )
                {
                    IInterface * pointer = unknow -> QueryInterface( iid );
                    if( pointer )
                    {
                        segment = dynamic_cast<T*>( pointer );
                        if( segment == NULL )
                        { 
                            IReferencedInterface * refered = 
                                dynamic_cast<IReferencedInterface *>( pointer );
                            SAFE_DECREF( refered );
                        }
                    }
                }
                return( segment != NULL );
            }


            inline bool  IsValid()
            {
                return( segment != NULL );
            }


            inline T *  operator ->()
            {
                return segment;
            }


            inline const T *  operator ->() const 
            {
                return segment;
            }

    };  //end class CInterface


}//end namespace atom


#endif
