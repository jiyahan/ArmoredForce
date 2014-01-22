#ifndef ATOM_OBJECT_ID_H
#define ATOM_OBJECT_ID_H
#include "../Common.h"



enum OBJECT_ID
{


        OID_EVENT_SPACE = OBJECT_ID_RESERVE + 1,


        OID_TCP_CONNECTOR,


        OID_TCP_LISTENER,


        OID_TCP_SELECT_MODEL,


		OID_TCP_IOCP_MODEL,


		OID_TCP_KQUEUE_MODEL,

		
		OID_TCP_EPOLL_MODEL,


        OID_XML_ELEMENT,

		
        OID_XML_DOCUMENT,


        OID_ATOM_END


}; //end enum OBJECT_ID 


#endif
