#include "CVariants.h"


atom::CVariants::CVariants() 
{
    variants.reserve( 16 );
}

atom::CVariants::CVariants(const CVariants & value) 
{
	* this = value;
}

atom::CVariants::~CVariants() 
{
}

void atom::CVariants::Clear() 
{
	variants.clear();
}

size_t atom::CVariants::Amount() const 
{
    return variants.size();
}

bool atom::CVariants::Append(const char * name, const CVariant & data) 
{
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

bool atom::CVariants::Remove(const char * name) 
{
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

bool atom::CVariants::Remove(size_t offset) 
{
	bool result = false;
	if( offset < variants.size() ) {
        result = true;
		variants.erase( variants.begin() + offset );
	}
    return result;
}

bool atom::CVariants::Obtain(const char * name, CVariant & data) const 
{
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

bool atom::CVariants::Obtain(size_t offset, CVariant & data) const 
{
	bool result = false;
	if( offset < variants.size() ) {
		data = variants[offset].second; result = true;
	}
    return result;
}

bool atom::CVariants::Obtain(size_t offset, a_string & name) const 
{
	bool result = false;
	if( offset < variants.size() ) {
		name = variants[offset].first; result = true;
	}
    return result;
}

atom::CVariants & atom::CVariants::operator =(const CVariants & value) 
{
    variants.clear();
	variants = value.variants;
	return( * this );
}
