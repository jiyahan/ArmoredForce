#ifdef __linux

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif 

#undef  _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE 1

#undef  _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS   64

#define MAX_EPOLL_THREAD    32
#define MAX_EPOLL_LENGTH    8000

#endif
