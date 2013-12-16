#ifdef  _WIN32

#include <Windows.h>
#include <WinDef.h>
#include <MMSystem.h>
#include <Process.h>
#include <IO.h>
#include <Time.h>
#include <Direct.h>
#include <WinSock2.h>
#include <MsWSock.h>
#include <DbgHelp.h>
#include <Excpt.h>

// Winsock的支持文件。如果使用MinGW32，链接的时候，必须加上 -lwsock32 与 -lws2_32 参数。
#endif
