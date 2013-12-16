#ifdef __APPLE__

typedef int8_t              I08;
typedef int16_t             I16;
typedef int32_t             I32;
typedef int64_t             I64;
typedef uint8_t             U08;
typedef uint16_t            U16;
typedef uint32_t            U32;
typedef uint64_t            U64;
typedef int                 SOCKET;

#define SOCKET_ERROR        -1
#define INVALID_SOCKET      -1
#define MAX_PATH            PATH_MAX
#define FLOAT_WORD_ORDER    BYTE_ORDER

#if defined(TARGET_OS_IPHONE)
#define TLS_DECLARE         
#define TLS_NOT_SUPPORT
#else
#define TLS_DECLARE         __thread
#endif

#endif
