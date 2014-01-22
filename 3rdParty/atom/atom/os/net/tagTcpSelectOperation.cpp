#include "tagTcpSelectOperation.h"


atom::tagTcpSelectOperation::tagTcpSelectOperation() : 
socket(INVALID_SOCKET),offset(0),length(0),target(0),serial(0)
{
}

atom::tagTcpSelectOperation::tagTcpSelectOperation(const tagTcpSelectOperation & value)
{
	*this = value;
}

atom::tagTcpSelectOperation::~tagTcpSelectOperation() 
{
}

atom::tagTcpSelectOperation & atom::tagTcpSelectOperation::operator=(const tagTcpSelectOperation & value) 
{
	socket = value.socket;
	memory = value.memory;
	offset = value.offset;
	length = value.length;
	target = value.target;
	serial = value.serial;
	return( *this );
}

bool atom::tagTcpSelectOperation::operator<(const tagTcpSelectOperation & value) const 
{
	return serial < value.serial;
}
