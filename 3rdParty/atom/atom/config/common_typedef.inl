#ifndef UNREFERENCED_PARAMETER
#define UNREFERENCED_PARAMETER(P) (void)(P)
#endif

// Define SAFE_serial operation
#ifndef SAFE_DELETE
#define SAFE_DELETE(p)          { if(p) { delete   (p);    (p)=NULL; } } 
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p)    { if(p) { delete[] (p);    (p)=NULL; } } 
#endif
#ifndef SAFE_DECREF
#define SAFE_DECREF(p)          { if(p) { (p) -> DecRef(); (p)=NULL; } } 
#endif

// Redefine INFINITE
#if defined(INFINITE)
#undef  INFINITE
#endif 
#define INFINITE ~(0)

// Define os bits type
#if defined(_AMD64_) || defined(_IA64_) || (__WORDSIZE == 64)
#define __OS64__
#else
#define __OS32__
#endif

// Check byte order
#ifndef BYTE_ORDER
#error Endianess not declared.
#endif

// Check byte order
#if BYTE_ORDER == PDP_ENDIAN || FLOAT_WORD_ORDER == PDP_ENDIAN
#error Middle-endian system not supported.
#endif

// Define max and min value
#define I08_MAX    0x7F
#define I16_MAX    0x7FFF
#define I32_MAX    0x7FFFFFFF
#define I64_MAX    0x7FFFFFFFFFFFFFFF

#define I08_MIN    ( -1 - 0x7F )
#define I16_MIN    ( -1 - 0x7FFF )
#define I32_MIN    ( -1 - 0x7FFFFFFF )
#define I64_MIN    ( -1 - 0x7FFFFFFFFFFFFFFF )

#define U08_MAX    0xFF
#define U16_MAX    0xFFFF
#define U32_MAX    0xFFFFFFFF
#define U64_MAX    0xFFFFFFFFFFFFFFFF

#define FLOAT_MAX  3.402823466e+38F
#define FLOAT_MIN  1.175494351e-38F

#define PI         3.1415926535f
#define PI2        6.2831853070f

// Define max and min
#ifndef atom_max
#define atom_max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef atom_min
#define atom_min(a,b) (((a) < (b)) ? (a) : (b))
#endif
