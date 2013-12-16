#ifdef __linux

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
#define TLS_DECLARE         __thread
#define FLOAT_WORD_ORDER    __FLOAT_WORD_ORDER

#endif
