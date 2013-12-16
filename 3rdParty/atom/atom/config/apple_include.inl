#ifdef __APPLE__

// Gcc linker must include -lpthread, -ldl static library option. 
#include <machine/endian.h>
#include <pthread.h>
#include <iconv.h>
#include <dirent.h>
#include <dlfcn.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/syslimits.h>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <execinfo.h>
#include <TargetConditionals.h>
#include <mach/mach.h>

#endif