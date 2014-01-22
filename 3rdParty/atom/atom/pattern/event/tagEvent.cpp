#include "tagEvent.h"


atom::tagEvent::tagEvent() : 
handle(0),source(0)
{
}

atom::tagEvent::tagEvent(const tagEvent & value)
{
	*this = value;
}

atom::tagEvent::~tagEvent() 
{
}

atom::tagEvent & atom::tagEvent::operator=(const tagEvent & value) 
{
	handle = value.handle;
	append = value.append;
	source = value.source;
	target = value.target;
	record = value.record;
	return( *this );
}
