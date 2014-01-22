#include "tagTcpKQueueOperation.h"


atom::tagTcpKQueueOperation::tagTcpKQueueOperation() : 
offset(0),length(0)
{
}

atom::tagTcpKQueueOperation::~tagTcpKQueueOperation() 
{
	Reset();
}

void atom::tagTcpKQueueOperation::Reset() 
{
    object = NULL;
	offset = 0;
	length = 0;
	memory.Clear();
}

void atom::tagTcpKQueueOperation::Attach(CObjectPtr & value) 
{
    object = value;
}

void atom::tagTcpKQueueOperation::Detach() 
{
    object = NULL;
}

atom::CObjectPtr atom::tagTcpKQueueOperation::Object() 
{
	return object;
}
