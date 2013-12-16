#ifdef __linux

// Gcc linker must include -lpthread, -ldl static library option. 
#include <features.h>
#include <endian.h>
#include <pthread.h>
#include <iconv.h>
#include <dirent.h>
#include <dlfcn.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <execinfo.h>
#include <typeinfo>

#endif
