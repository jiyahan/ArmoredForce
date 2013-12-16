#include "CVariants.h"
//Begin section for file CVariants.cpp
//TODO: Add definitions that you want preserved
//End section for file CVariants.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariants::CVariants() 
{
    //TODO Auto-generated method stub
    variants.reserve( 16 );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariants::CVariants(const CVariants & value) 
{
    //TODO Auto-generated method stub
	* this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariants::~CVariants() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CVariants::Clear() 
{
    //TODO Auto-generated method stub
	variants.clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CVariants::Amount() const 
{
    //TODO Auto-generated method stub
    return variants.size();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariants::Append(const char * name, const CVariant & data) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( name )
	{
		bool found = false;
		for( CVariantsBind::iterator it = 
			variants.begin(); it != variants.end(); it ++ ) {
            found = ( it -> first == name );
			if( found ) break;
		}

		if( false == found ) {
			result = true;
			variants.push_back( make_pair(name, data) );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariants::Remove(const char * name) 
{
    //TODO Auto-generated method stub
	if( !name ) return false;

	bool result = false;
	for( CVariantsBind::iterator it = 
		variants.begin(); it != variants.end(); it ++ ) 
	{
		if( it -> first == name )  {
            variants.erase( it ); 
            result = true; break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariants::Remove(size_t offset) 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( offset < variants.size() ) {
        result = true;
		variants.erase( variants.begin() + offset );
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariants::Obtain(const char * name, CVariant & data) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( name )
	{
        for( CVariantsBind::const_iterator 
            it = variants.begin(); it != variants.end(); ++ it ) 
        {
            if( it -> first == name ) {
                data = it -> second; 
                result = true; break;
            }
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariants::Obtain(size_t offset, CVariant & data) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( offset < variants.size() ) {
		data = variants[offset].second; result = true;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariants::Obtain(size_t offset, a_string & name) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( offset < variants.size() ) {
		name = variants[offset].first; result = true;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariants & atom::CVariants::operator =(const CVariants & value) 
{
    //TODO Auto-generated method stub
    variants.clear();
	variants = value.variants;
	return( * this );
}
