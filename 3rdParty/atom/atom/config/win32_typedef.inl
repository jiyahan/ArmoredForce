#ifdef  _WIN32

#ifdef __GUNC__
	typedef signed char         I08;
	typedef signed short        I16;
	typedef signed int          I32;
	typedef signed long         I64;
	typedef unsigned char       U08;
	typedef unsigned short      U16;
	typedef unsigned int        U32;
	typedef unsigned long       U64;
	#define TLS_DECLARE         __thread  
#endif

#ifdef _MSC_VER
	typedef signed   __int8     I08;
	typedef signed   __int16    I16;
	typedef signed   __int32    I32;
	typedef signed   __int64    I64;
	typedef unsigned __int8     U08;
	typedef unsigned __int16    U16;
	typedef unsigned __int32    U32;
	typedef unsigned __int64    U64;
	#define TLS_DECLARE         __declspec( thread )
#endif

// _X86_ && _IA64_ && _AMD64_
#if defined(_X86_) || defined(_IA64_) || defined(_AMD64_)
	#define LITTLE_ENDIAN       1234
	#define BIG_ENDIAN          4321
	#define PDP_ENDIAN          3412
	#define BYTE_ORDER          LITTLE_ENDIAN

	#ifndef FLOAT_WORD_ORDER
	#define FLOAT_WORD_ORDER    BYTE_ORDER
	#endif    
#endif 

#endif
