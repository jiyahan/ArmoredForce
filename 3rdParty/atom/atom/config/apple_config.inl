#ifdef __APPLE__

#undef  _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64

#define MAX_KQUEUE_THREAD 32

#endif