#include "tagVariant.h"
#include "../../enumeration/VARIANT_TYPE.h"
//Begin section for file tagVariant.cpp
//TODO: Add definitions that you want preserved
//End section for file tagVariant.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagVariant::tagVariant() : 
type(VT_UNKNOW)
{
    //TODO Auto-generated method stub
	base.u = 0;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagVariant::tagVariant(const tagVariant & value) : 
type(VT_UNKNOW)
{
    //TODO Auto-generated method stub
	base.u = 0;
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagVariant::~tagVariant() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::tagVariant & atom::tagVariant::operator=(const tagVariant & value) 
{
    //TODO Auto-generated method stub
	type = value.type;
	base = value.base;
	data = value.data;
	return( *this );
}
