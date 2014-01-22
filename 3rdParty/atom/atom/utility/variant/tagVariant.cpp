#include "tagVariant.h"
#include "../../enumeration/VARIANT_TYPE.h"


atom::tagVariant::tagVariant() : 
type(VT_UNKNOW)
{
	base.u = 0;
}

atom::tagVariant::tagVariant(const tagVariant & value) : 
type(VT_UNKNOW)
{
	base.u = 0;
	*this = value;
}

atom::tagVariant::~tagVariant() 
{
}

atom::tagVariant & atom::tagVariant::operator=(const tagVariant & value) 
{
	type = value.type;
	base = value.base;
	data = value.data;
	return( *this );
}
