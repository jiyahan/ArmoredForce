#ifndef CBYTESWAP_H
#define CBYTESWAP_H
//Begin section for file CByteSwap.h
//TODO: Add definitions that you want preserved
//End section for file CByteSwap.h
#include "../../Common.h"



namespace atom
{



    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    class CByteSwap
    {
        //Begin section for atom::CByteSwap
        //TODO: Add attributes that you want preserved
        //End section for atom::CByteSwap



        public:

            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static U16 swap16(U16 value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static U32 swap32(U32 value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            inline static U64 swap64(U64 value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class T>
            inline static T hton(T value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class T>
            inline static T ntoh(T value); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class T>
            inline static void hton_float(T & inner, T & outer); 



            //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
            template<class T>
            inline static void ntoh_float(T & inner, T & outer); 



    };  //end class CByteSwap


}//end namespace atom


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U16 atom::CByteSwap::swap16(U16 value) 
{
    //TODO Auto-generated method stub
    return ( (value & 0xFF00) >> 8 ) | ( (value & 0x00FF) << 8 ); 
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CByteSwap::swap32(U32 value) 
{
    //TODO Auto-generated method stub
    return 
        ( (value & 0xFF000000) >> 24 ) |
        ( (value & 0x00FF0000) >> 8  ) |
        ( (value & 0x0000FF00) << 8  ) |
        ( (value & 0x000000FF) << 24 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U64 atom::CByteSwap::swap64(U64 value) 
{
    //TODO Auto-generated method stub
    return 
        ( (value & 0xFF00000000000000) >> 56 ) |
        ( (value & 0x00FF000000000000) >> 40 ) |
        ( (value & 0x0000FF0000000000) >> 24 ) |
        ( (value & 0x000000FF00000000) >> 8  ) |
        ( (value & 0x00000000FF000000) << 8  ) |
        ( (value & 0x0000000000FF0000) << 24 ) |
        ( (value & 0x000000000000FF00) << 40 ) |
        ( (value & 0x00000000000000FF) << 56 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
template<class T>
T atom::CByteSwap::hton(T value) 
{
    //TODO Auto-generated method stub
    #if BYTE_ORDER == LITTLE_ENDIAN

    // 如果是小端系统，则需要进行字节变换；
    T result = value; size_t size = sizeof(T); 
    if( size == 2 )
    {
        union{ T t; U16 u; } i, o;
        i.t = value;
        o.u = swap16( i.u );
        result = o.t;
    }
    else
    if( size == 4 )
    {
        union{ T t; U32 u; } i, o;
        i.t = value;
        o.u = swap32( i.u );
        result = o.t;
    }
    else
    if( size == 8 )
    {
        union{ T t; U64 u; } i, o;
        i.t = value;
        o.u = swap64( i.u );
        result = o.t;
    }
    return result;

    #elif BYTE_ORDER == BIG_ENDIAN

    // 如果是大端系统，则无需进行字节变换；
    return value;

    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
template<class T>
T atom::CByteSwap::ntoh(T value) 
{
    //TODO Auto-generated method stub
    #if BYTE_ORDER == LITTLE_ENDIAN

    // 如果是小端系统，则需要进行字节变换；
    T result = value; size_t size = sizeof(T); 
    if( size == 2 )
    {
        union{ T t; U16 u; } i, o;
        i.t = value;
        o.u = swap16( i.u );
        result = o.t;
    }
    else
    if( size == 4 )
    {
        union{ T t; U32 u; } i, o;
        i.t = value;
        o.u = swap32( i.u );
        result = o.t;
    }
    else
    if( size == 8 )
    {
        union{ T t; U64 u; } i, o;
        i.t = value;
        o.u = swap64( i.u );
        result = o.t;
    }
    return result;

    #elif BYTE_ORDER == BIG_ENDIAN

    // 如果是大端系统，则无需进行字节变换；
    return value;

    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
template<class T>
void atom::CByteSwap::hton_float(T & inner, T & outer) 
{
    //TODO Auto-generated method stub
    #if FLOAT_WORD_ORDER == LITTLE_ENDIAN

    // 如果是小端系统，则需要进行字节变换；
    // =操作符可能会改变某些浮点值，用memcpy代替；
    size_t size = sizeof(T); 
    if( size == 4 )
    {
        U32 i, o;
        memcpy( & i, & inner, sizeof(T) );
        o = swap32( i );
        memcpy( & outer, & o, sizeof(T) );
    }
    else
    if( size == 8 )
    {
        U64 i, o;
        memcpy( & i, & inner, sizeof(T) );
        o = swap64( i );
        memcpy( & outer, & o, sizeof(T) );
    }

    #elif FLOAT_WORD_ORDER == BIG_ENDIAN

    // 如果是大端系统，则无需进行字节变换；
    outer = inner;

    #endif
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
template<class T>
void atom::CByteSwap::ntoh_float(T & inner, T & outer) 
{
    //TODO Auto-generated method stub
    #if FLOAT_WORD_ORDER == LITTLE_ENDIAN

    // 如果是小端系统，则需要进行字节变换；
    // =操作符可能会改变某些浮点值，用memcpy代替；
    size_t size = sizeof(T); 
    if( size == 4 )
    {
        U32 i, o;
        memcpy( & i, & inner, sizeof(T) );
        o = swap32( i );
        memcpy( & outer, & o, sizeof(T) );
    }
    else
    if( size == 8 )
    {
        U64 i, o;
        memcpy( & i, & inner, sizeof(T) );
        o = swap64( i );
        memcpy( & outer, & o, sizeof(T) );
    }

    #elif FLOAT_WORD_ORDER == BIG_ENDIAN

    // 如果是大端系统，则无需进行字节变换；
    outer = inner;

    #endif
}

#endif
