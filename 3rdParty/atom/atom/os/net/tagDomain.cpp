#include "tagDomain.h"


atom::tagDomain::tagDomain() : 
port(0)
{
}

atom::tagDomain::tagDomain(const tagDomain & value) 
{
	* this = value;
}

atom::tagDomain::~tagDomain() 
{
}

atom::tagDomain & atom::tagDomain::operator=(const tagDomain & value) 
{
	host = value.host;
	port = value.port;
	return( * this );
}
