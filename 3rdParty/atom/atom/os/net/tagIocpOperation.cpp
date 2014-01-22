#include "tagIocpOperation.h"


atom::tagIocpOperation::tagIocpOperation() 
{
	#ifdef _WIN32
	op = 0;
	hs = INVALID_SOCKET;
	
	ZeroMemory( & ol, sizeof(CIocpOverlap) );
	ZeroMemory( & wb, sizeof(CIocpBuffer)  );
	#endif
}

atom::tagIocpOperation::~tagIocpOperation() 
{
}

void atom::tagIocpOperation::Reset() 
{
	#ifdef _WIN32
	op = 0;
	hs = INVALID_SOCKET;

	ZeroMemory( & ol, sizeof(CIocpOverlap) );
	ZeroMemory( & wb, sizeof(CIocpBuffer)  );

	mb.Clear(); Detach();
	#endif
}

bool atom::tagIocpOperation::Attach(CObjectPtr & object) 
{
	#ifdef _WIN32
	ob = object;
    return true;
	#else
	UNREFERENCED_PARAMETER( object );
	return false;
	#endif

}

void atom::tagIocpOperation::Detach() 
{
	#ifdef _WIN32
    ob = NULL;
	#endif
}

U64 atom::tagIocpOperation::GetObjectName() 
{
	U64 name = 0;
	#ifdef _WIN32
	if( ob ) name = ob -> GetName();
	#endif
	return name;
}

atom::CObjectPtr atom::tagIocpOperation::GetObject() 
{
	#ifdef _WIN32
	return ob;
	#else
	return CObjectPtr();
	#endif
}
