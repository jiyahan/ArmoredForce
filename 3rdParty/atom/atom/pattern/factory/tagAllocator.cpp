#include "tagAllocator.h"


atom::tagAllocator::tagAllocator() : 
lower(0),upper(0)
{
}

atom::tagAllocator::~tagAllocator() 
{
	Clear();
}

void atom::tagAllocator::Clear() 
{
    lower = 0;
	upper = 0;
	point = NULL;
}
