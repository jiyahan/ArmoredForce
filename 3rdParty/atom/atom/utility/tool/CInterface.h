#ifndef CINTERFACE_H
#define CINTERFACE_H
//Begin section for file CInterface.h
//TODO: Add definitions that you want preserved
//End section for file CInterface.h
#include "../../Common.h"
#include "../../interface/IInterface.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template <class T>
    class CInterface
    {

        //Begin section for atom::CInterface
        //TODO: Add attributes that you want preserved
        //End section for atom::CInterface

        private:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            T * segment;




        public:


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline CInterface(): 
            segment(NULL)
            {
                //TODO Auto-generated method stub
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline virtual ~CInterface()
            {
                //TODO Auto-generated method stub
                if( segment )
                {
                    IReferencedInterface * refered = 
                        dynamic_cast<IReferencedInterface *>( segment );
                    SAFE_DECREF( refered );
                    segment = NULL;
                }
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline void Reset()
            {
                //TODO Auto-generated method stub
                if( segment )
                {
                    IReferencedInterface * refered = 
                        dynamic_cast<IReferencedInterface *>( segment );
                    SAFE_DECREF( refered );
                    segment = NULL;
                }
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  Mount(IInterface * unknow, U32 iid)
            {
                //TODO Auto-generated method stub
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


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline bool  IsValid()
            {
                //TODO Auto-generated method stub
                return( segment != NULL );
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline T *  operator ->()
            {
                //TODO Auto-generated method stub
                return segment;
            }


            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline const T *  operator ->() const 
            {
                //TODO Auto-generated method stub
                return segment;
            }

    };  //end class CInterface


}//end namespace atom


#endif
