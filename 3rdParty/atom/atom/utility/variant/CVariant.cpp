#include "CVariant.h"
#include "../../os/character/CCharacter.h"
#include "../../enumeration/VARIANT_TYPE.h"
//Begin section for file CVariant.cpp
//TODO: Add definitions that you want preserved
//End section for file CVariant.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(const CVariant & value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(I08 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(I16 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(I32 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(I64 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(U08 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(U16 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(U32 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(U64 value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(float value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(double value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(const char * value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::CVariant(const CMemory & value) 
{
    //TODO Auto-generated method stub
	*this = value;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::~CVariant() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U32 atom::CVariant::Type() const
{
    //TODO Auto-generated method stub
	return variant.type;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
size_t atom::CVariant::Size() const
{
    //TODO Auto-generated method stub
	size_t result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = sizeof(I64);
		break;
	case VT_U_INT:
		result = sizeof(U64);
		break;
	case VT_FLOAT:
		result = sizeof(double);
		break;
	case VT_A_STR:
	case VT_W_STR:
	case VT_BLOCK:
		result = variant.data.GetLength();
		break;
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CVariant::Clear() 
{
    //TODO Auto-generated method stub
	variant.type   = VT_UNKNOW;
	variant.base.u = 0;
	variant.data.Clear();
	convert.Clear();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator I08()  const
{
    //TODO Auto-generated method stub
	I08 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<I08>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<I08>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<I08>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<I08>( strtol( variant.data.Query<char>   (), & stop, 10 ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<I08>( wcstol( variant.data.Query<wchar_t>(), & stop, 10 ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator I16()  const
{
    //TODO Auto-generated method stub
	I16 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<I16>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<I16>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<I16>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<I16>( strtol( variant.data.Query<char>   (), & stop, 10 ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<I16>( wcstol( variant.data.Query<wchar_t>(), & stop, 10 ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator I32()  const
{
    //TODO Auto-generated method stub
	I32 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<I32>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<I32>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<I32>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<I32>( strtol( variant.data.Query<char>   (), & stop, 10 ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<I32>( wcstol( variant.data.Query<wchar_t>(), & stop, 10 ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator I64()  const
{
    //TODO Auto-generated method stub
	I64 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<I64>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<I64>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<I64>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) 
		{
			char    * stop = NULL;
			#if defined(_WIN32)
			result = static_cast<I64>( _strtoi64( variant.data.Query<char>(), & stop, 10 ) );
			#else
			result = static_cast<I64>(  strtoll ( variant.data.Query<char>(), & stop, 10 ) );
			#endif
		}
		break;
	case VT_W_STR:
		if( variant.data ) 
		{
			wchar_t * stop = NULL;
			#if defined(_WIN32)
			result = static_cast<I64>( _wcstoi64( variant.data.Query<wchar_t>(), & stop, 10 ) );
			#else
			result = static_cast<I64>(  wcstoll ( variant.data.Query<wchar_t>(), & stop, 10 ) );
			#endif
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator U08()  const
{
    //TODO Auto-generated method stub
	U08 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<U08>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<U08>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<U08>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<U08>( strtoul( variant.data.Query<char>   (), & stop, 10 ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<U08>( wcstoul( variant.data.Query<wchar_t>(), & stop, 10 ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator U16()  const
{
    //TODO Auto-generated method stub
	U16 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<U16>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<U16>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<U16>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<U16>( strtoul( variant.data.Query<char>   (), & stop, 10 ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<U16>( wcstoul( variant.data.Query<wchar_t>(), & stop, 10 ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator U32()  const
{
    //TODO Auto-generated method stub
	U32 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<U32>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<U32>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<U32>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<U32>( strtoul( variant.data.Query<char>   (), & stop, 10 ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<U32>( wcstoul( variant.data.Query<wchar_t>(), & stop, 10 ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator U64()  const
{
    //TODO Auto-generated method stub
	U64 result = 0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<U64>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<U64>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<U64>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) 
		{
			char * stop = NULL;
			#if defined(_WIN32)
			result = static_cast<U64>( _strtoui64( variant.data.Query<char>(), & stop, 10 ) );
			#else
			result = static_cast<U64>(  strtoull ( variant.data.Query<char>(), & stop, 10 ) );
			#endif
		}
		break;
	case VT_W_STR:
		if( variant.data ) 
		{
			wchar_t * stop = NULL;
			#if defined(_WIN32)
			result = static_cast<U64>( _wcstoui64( variant.data.Query<wchar_t>(), & stop, 10 ) );
			#else
			result = static_cast<U64>(  wcstoull ( variant.data.Query<wchar_t>(), & stop, 10 ) );
			#endif
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator float()  const
{
    //TODO Auto-generated method stub
	float result = 0.0f;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<float>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<float>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<float>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<float>( strtod( variant.data.Query<char>   (), & stop ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<float>( wcstod( variant.data.Query<wchar_t>(), & stop ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator double()  const
{
    //TODO Auto-generated method stub
	double result = 0.0;
	switch( variant.type )
	{
	case VT_S_INT:
		result = static_cast<double>( variant.base.i );
		break;
	case VT_U_INT:
		result = static_cast<double>( variant.base.u );
		break;
	case VT_FLOAT:
		result = static_cast<double>( variant.base.f );
		break;
	case VT_A_STR:
		if( variant.data ) {
			char    * stop = NULL;
			result = static_cast<double>( strtod( variant.data.Query<char>   (), & stop ) );
		}
		break;
	case VT_W_STR:
		if( variant.data ) {
			wchar_t * stop = NULL;
			result = static_cast<double>( wcstod( variant.data.Query<wchar_t>(), & stop ) );
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator const char *()  const
{
    //TODO Auto-generated method stub
	char * result = NULL;
	switch( variant.type )
	{
	case VT_S_INT:
		{
			if( !convert )
			{
				char msg[256];
				sprintf( msg, "%lli", variant.base.i );

				size_t length = strlen( msg );
				if( convert.Alloc( length + 1 ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( msg, length );
				}
			}
			result = convert.Query<char>();
		}
		break;
	case VT_U_INT:
		{
			if( !convert )
			{
				char msg[256];
				sprintf( msg, "%llu", variant.base.i );

				size_t length = strlen( msg );
				if( convert.Alloc( length + 1 ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( msg, length );
				}
			}
			result = convert.Query<char>();
		}
		break;
	case VT_FLOAT:
		{
			if( !convert )
			{
				char msg[256];
				sprintf( msg, "%f", variant.base.f );

				size_t length = strlen( msg );
				if( convert.Alloc( length + 1 ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( msg, length );
				}
			}
			result = convert.Query<char>();
		}
		break;
	case VT_A_STR:
		{
			result = variant.data.Query<char>();
		}
		break;
	case VT_W_STR:
		{
			if( !convert )
			{
				a_string value = CCharacter::
					UnicodeToMultiBytes( variant.data.Query<wchar_t>() );

				size_t length = value.length();
				if( convert.Alloc( length + 1 ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( value.c_str(), length );
				}
			}
			result = convert.Query<char>();
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator const wchar_t *()  const
{
    //TODO Auto-generated method stub
	wchar_t * result = NULL;
	switch( variant.type )
	{
	case VT_S_INT:
		{
			if( !convert )
			{
				wchar_t msg[256];
				swprintf( msg, 256, L"%lli", variant.base.i );

				size_t length = wcslen( msg ) * sizeof( wchar_t );
				if( convert.Alloc( length + sizeof(wchar_t) ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( msg, length );
				}
			}
			result = convert.Query<wchar_t>();
		}
		break;
	case VT_U_INT:
		{
			if( !convert )
			{
				wchar_t msg[256];
				swprintf( msg, 256, L"%llu", variant.base.u );

				size_t length = wcslen( msg ) * sizeof( wchar_t );
				if( convert.Alloc( length + sizeof(wchar_t) ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( msg, length );
				}
			}
			result = convert.Query<wchar_t>();
		}
		break;
	case VT_FLOAT:
		{
			if( !convert )
			{
				wchar_t msg[256];
				swprintf( msg, 256, L"%f", variant.base.f );

				size_t length = wcslen( msg ) * sizeof( wchar_t );
				if( convert.Alloc( length + sizeof(wchar_t) ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( msg, length );
				}
			}
			result = convert.Query<wchar_t>();
		}
		break;
	case VT_A_STR:
		{
			if( !convert )
			{
				a_wstring value = CCharacter::
					MultiBytesToUnicode( variant.data.Query<char>() );

				size_t length = value.length() * sizeof( wchar_t );
				if( convert.Alloc( length + sizeof(wchar_t) ) ) 
				{
					memset( convert, 0, convert.GetCapacity() );
					convert.Store( value.c_str(), length );
				}
			}
			result = convert.Query<wchar_t>();
		}
		break;
	case VT_W_STR:
		{
			result = variant.data.Query<wchar_t>();
		}
		break;
	case VT_BLOCK:
		// not support to covert from blob data;
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant::operator atom::CMemory()  const
{
    //TODO Auto-generated method stub
	return variant.data;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(I08 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_S_INT;
	variant.base.i = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(I16 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_S_INT;
	variant.base.i = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(I32 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_S_INT;
	variant.base.i = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(I64 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_S_INT;
	variant.base.i = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(U08 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_U_INT;
	variant.base.u = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(U16 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_U_INT;
	variant.base.u = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(U32 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_U_INT;
	variant.base.u = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(U64 value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_U_INT;
	variant.base.u = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(float value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_FLOAT;
	variant.base.f = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(double value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type   = VT_FLOAT;
	variant.base.f = value;
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(const char * value) 
{
    //TODO Auto-generated method stub
	Clear();
	U08 type = ST_TXT;
	if( value ) {
		type = Parse( value );
	}

	if( type == U08(ST_INT) )
	{
		// Initiate as integer;
		char *  stop   = NULL;
		variant.type   = VT_S_INT;

		// Convert from string;
		#if defined(_WIN32)
		variant.base.i = static_cast<I64>( _strtoi64(value, & stop, 10) );
		#else
		variant.base.i = static_cast<I64>(  strtoll (value, & stop, 10) );
		#endif
	}
	else
	if( type == U08(ST_FLT) )
	{
		// Initiate as float point;
		char *  stop   = NULL;
		variant.type   = VT_FLOAT;
		variant.base.f = static_cast<double>( strtod(value, & stop) );
	}
	else
	if( type == U08(ST_TXT) )
	{
		// Initiate as string;
		variant.type = VT_A_STR;

		// Calculate string length;
		size_t length = 0;
		if( value ) {
			length = strlen( value );
		}

		// Alloc memory and store it;
		if( variant.data.Alloc( length + 1 ) ) 
		{
			memset( variant.data, 0, variant.data.GetCapacity() );
			if( value ) {
				variant.data.Store( value, length );
			}
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	Clear();
	U08 type = ST_TXT;
	if( value ) {
		type = Parse( value );
	}

	if( type == U08(ST_INT) )
	{
		// Initiate as integer
		wchar_t * stop = NULL;
		variant.type   = VT_S_INT;

		// Convert from string;
		#if defined(_WIN32)
		variant.base.i = static_cast<I64>( _wcstoi64(value, & stop, 10) );
		#else
		variant.base.i = static_cast<I64>(  wcstoll (value, & stop, 10) );
		#endif
	}
	else
	if( type == U08(ST_FLT) )
	{
		// Initiate as float point
		wchar_t * stop = NULL;
		variant.type   = VT_FLOAT;
		variant.base.f = static_cast<double>( wcstod(value, & stop) );
	}
	else
	if( type == U08(ST_TXT) )
	{
		variant.type = VT_W_STR;

		// Calculate string length;
		size_t length = 0;
		size_t origin = sizeof( wchar_t );

		if( value ) {
			length = wcslen( value ) * origin;
		}

		// Alloc memory and store it;
		if( variant.data.Alloc(length + origin) ) 
		{
			memset( variant.data, 0, variant.data.GetCapacity() );
			if( value ) {
				variant.data.Store( value, length );
			}
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(const CMemory & value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type = VT_BLOCK;
	variant.data = value.Clone();
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator=(const CVariant & value) 
{
    //TODO Auto-generated method stub
	Clear();
	variant.type = value.variant.type;
	variant.base = value.variant.base;
	variant.data = value.variant.data.Clone();
	convert      = value.convert     .Clone();
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(I08 value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(I16 value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(I32 value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(I64 value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i == value );
		break;
	case VT_U_INT:
		result = ( variant.base.u == static_cast<U64>   (value) );
		break;
	case VT_FLOAT:
		result = ( variant.base.f == static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<I64>(*this) == value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(U08 value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(U16 value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(U32 value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(U64 value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i == static_cast<I64>   (value) );
		break;
	case VT_U_INT:
		result = ( variant.base.u == value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f == static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<U64>(*this) == value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(float value)  const
{
    //TODO Auto-generated method stub
	return ( *this ) == static_cast<double>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(double value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i == value );
		break;
	case VT_U_INT:
		result = ( variant.base.u == value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f == value );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<double>(*this) == value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(const char * value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const char * data = *this;
				if( data ) {
					result = ( strcmp(data, value) == 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(const wchar_t * value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const wchar_t * data = *this;
				if( data ) {
					result = ( wcscmp(data, value) == 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(const CMemory & value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	if( variant.type == VT_BLOCK )
	{
		if( variant.data.GetLength() == value.GetLength() ) {
			result = ( 0 == memcmp( variant.data, value, value.GetLength() ) );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator==(const CVariant & value)  const
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			result = (*this) == casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			result = (*this) == casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			result = (*this) == casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			result = (*this) == casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			result = (*this) == casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			result = (*this) == casted;
		}
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(I08 value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(I16 value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(I32 value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(I64 value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i += value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u += value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f += value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(U08 value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(U16 value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(U32 value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(U64 value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i += value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u += value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f += value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(float value) 
{
    //TODO Auto-generated method stub
	( *this ) += static_cast<double>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(double value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.i + value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.u + value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f += value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(const char * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		switch( variant.type )
		{
		case VT_S_INT:
		case VT_U_INT:
		case VT_FLOAT:
			{
				U08 type = Parse( value );
				if( type == U08(ST_INT) ) 
				{
					CVariant data( value );
					( *this ) += static_cast<I64>   ( data );
				}
				else
				if( type == U08(ST_FLT) )
				{
					CVariant data( value );
					( *this ) += static_cast<double>( data );
				}
			}
			break;
		case VT_A_STR:
			{
				// combin string;
				CMemory data;
				size_t length = variant.data.GetLength() + strlen( value );

				convert.Clear();
				if( data.Alloc(length + 1) )
				{
					data.SetLength( length );
					memset( data, 0, data.GetCapacity() );

					// if origin string is not empty, copy it.
					if( variant.data ) {
						strcpy( data.Query<char>(), variant.data.Query<char>() );
					}

					// copy append string.
					strcat( data.Query<char>(), value );

					// swap memory data;
					variant.data = data;
				}
			}
			break;
		case VT_W_STR:
			{
				// combin string;
				a_wstring temp = CCharacter::MultiBytesToUnicode( value );

				CMemory data;
				size_t length = variant.data.GetLength() + temp.length() * sizeof( wchar_t );

				convert.Clear();
				if( data.Alloc( length + sizeof(wchar_t) ) )
				{
					data.SetLength( length );
					memset( data, 0, data.GetCapacity() );

					// if origin string is not empty, copy it.
					if( variant.data ) {
						wcscpy( data.Query<wchar_t>(), variant.data.Query<wchar_t>() );
					}

					// copy append string.
					wcscat( data.Query<wchar_t>(), temp.c_str() );

					// swap memory data;
					variant.data = data;
				}
			}
			break;
		case VT_BLOCK:
			// do nothing;
			break;
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		switch( variant.type )
		{
		case VT_S_INT:
		case VT_U_INT:
		case VT_FLOAT:
			{
				U08 type = Parse( value );
				if( type == U08(ST_INT) ) 
				{
					CVariant data( value );
					( *this ) += static_cast<I64>   ( data );
				}
				else
				if( type == U08(ST_FLT) )
				{
					CVariant data( value );
					( *this ) += static_cast<double>( data );
				}
			}
			break;
		case VT_A_STR:
			{
				// combin string;
				a_string temp = CCharacter::UnicodeToMultiBytes( value );

				CMemory data;
				size_t length = variant.data.GetLength() + temp.length();

				convert.Clear();
				if( data.Alloc(length + 1) )
				{
					data.SetLength( length );
					memset( data, 0, data.GetCapacity() );

					// if origin string is not empty, copy it.
					if( variant.data ) {
						strcpy( data.Query<char>(), variant.data.Query<char>() );
					}
					
					// copy append string.
					strcat( data.Query<char>(), temp.c_str() );

					// swap memory data;
					variant.data = data;
				}
			}
			break;
		case VT_W_STR:
			{
				// combin string;
				CMemory data;
				size_t length = variant.data.GetLength() + wcslen( value ) * sizeof( wchar_t );

				convert.Clear();
				if( data.Alloc( length + sizeof(wchar_t) ) )
				{
					data.SetLength( length );
					memset( data, 0, data.GetCapacity() );

					// if origin string is not empty, copy it.
					if( variant.data ) {
						wcscpy( data.Query<wchar_t>(), variant.data.Query<wchar_t>() );
					}

					// copy append string.
					wcscat( data.Query<wchar_t>(), value );

					// swap memory data;
					variant.data = data;
				}
			}
			break;
		case VT_BLOCK:
			// do nothing;
			break;
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(const CMemory & value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		switch( variant.type )
		{
		case VT_S_INT:
			// do nothing;
			break;
		case VT_U_INT:
			// do nothing;
			break;
		case VT_FLOAT:
			// do nothing;
			break;
		case VT_A_STR:
			// do nothing;
			break;
		case VT_W_STR:
			// do nothing;
			break;
		case VT_BLOCK:
			{
				CMemory data;
				size_t length = variant.data.GetLength() + value.GetLength();
				
				convert.Clear();
				if( data.Alloc(length) )
				{
					data.SetLength( length );
					memset( data, 0, data.GetCapacity() );

					// if origin block is not empty, copy it.
					if( variant.data ) {
						memcpy( data, variant.data, variant.data.GetLength() );
					}

					// copy append block.
					memcpy( data.Query<char>() + variant.data.GetLength(), value, value.GetLength() );

					// swap block data.
					variant.data = data;
				}
			}
			break;
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator+=(const CVariant & value) 
{
    //TODO Auto-generated method stub
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			( *this ) += casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			( *this ) += casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			( *this ) += casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			( *this ) += casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			( *this ) += casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			( *this ) += casted;
		}
		break;
	}
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(I08 value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(I16 value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(I32 value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(I64 value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i -= value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u -= value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f -= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(U08 value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(U16 value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(U32 value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(U64 value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i -= value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u -= value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f -= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(float value) 
{
    //TODO Auto-generated method stub
	( *this ) -= static_cast<double>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(double value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.i - value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.u - value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f -= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(const char * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		U08 type = Parse( value );
		if( type == U08(ST_INT) ) 
		{
			CVariant data( value );
			( *this ) -= static_cast<I64>   ( data );
		}
		else
		if( type == U08(ST_FLT) )
		{
			CVariant data( value );
			( *this ) -= static_cast<double>( data );
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		U08 type = Parse( value );
		if( type == U08(ST_INT) ) 
		{
			CVariant data( value );
			( *this ) -= static_cast<I64>   ( data );
		}
		else
		if( type == U08(ST_FLT) )
		{
			CVariant data( value );
			( *this ) -= static_cast<double>( data );
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(const CMemory & value) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator-=(const CVariant & value) 
{
    //TODO Auto-generated method stub
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			( *this ) -= casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			( *this ) -= casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			( *this ) -= casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			( *this ) -= casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			( *this ) -= casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			( *this ) -= casted;
		}
		break;
	}
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(I08 value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(I16 value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(I32 value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(I64 value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i *= value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u *= value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f *= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(U08 value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(U16 value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(U32 value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(U64 value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i *= value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u *= value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f *= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(float value) 
{
    //TODO Auto-generated method stub
	( *this ) *= static_cast<double>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(double value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.i * value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.u * value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f *= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(const char * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		U08 type = Parse( value );
		if( type == U08(ST_INT) ) 
		{
			CVariant data( value );
			( *this ) *= static_cast<I64>   ( data );
		}
		else
		if( type == U08(ST_FLT) )
		{
			CVariant data( value );
			( *this ) *= static_cast<double>( data );
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		U08 type = Parse( value );
		if( type == U08(ST_INT) ) 
		{
			CVariant data( value );
			( *this ) *= static_cast<I64>   ( data );
		}
		else
		if( type == U08(ST_FLT) )
		{
			CVariant data( value );
			( *this ) *= static_cast<double>( data );
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(const CMemory & value) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator*=(const CVariant & value) 
{
    //TODO Auto-generated method stub
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			( *this ) *= casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			( *this ) *= casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			( *this ) *= casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			( *this ) *= casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			( *this ) *= casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			( *this ) *= casted;
		}
		break;
	}
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(I08 value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(I16 value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(I32 value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<I64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(I64 value) 
{
    //TODO Auto-generated method stub
	// if value is zero, assign paramater as double value;
	if( value == 0 ) {
		return ( *this ) /= 0.0;
	}

	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i /= value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u /= value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f /= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(U08 value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(U16 value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(U32 value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<U64>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(U64 value) 
{
    //TODO Auto-generated method stub
	// if value is zero, assign paramater as double value;
	if( value == 0 ) {
		return ( *this ) /= 0.0;
	}

	switch( variant.type )
	{
	case VT_S_INT:
		variant.base.i /= value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.base.u /= value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f /= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(float value) 
{
    //TODO Auto-generated method stub
	( *this ) /= static_cast<double>( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(double value) 
{
    //TODO Auto-generated method stub
	switch( variant.type )
	{
	case VT_S_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.i / value;
		convert.Clear();
		break;
	case VT_U_INT:
		variant.type   = VT_FLOAT;
		variant.base.f = variant.base.u / value;
		convert.Clear();
		break;
	case VT_FLOAT:
		variant.base.f /= value;
		convert.Clear();
		break;
	case VT_A_STR:
		// do nothing;
		break;
	case VT_W_STR:
		// do nothing;
		break;
	case VT_BLOCK:
		// do nothing;
		break;
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(const char * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		U08 type = Parse( value );
		if( type == U08(ST_INT) ) 
		{
			CVariant data( value );
			( *this ) /= static_cast<I64>   ( data );
		}
		else
		if( type == U08(ST_FLT) )
		{
			CVariant data( value );
			( *this ) /= static_cast<double>( data );
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	if( value )
	{
		U08 type = Parse( value );
		if( type == U08(ST_INT) ) 
		{
			CVariant data( value );
			( *this ) /= static_cast<I64>   ( data );
		}
		else
		if( type == U08(ST_FLT) )
		{
			CVariant data( value );
			( *this ) /= static_cast<double>( data );
		}
	}
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(const CMemory & value) 
{
    //TODO Auto-generated method stub
	UNREFERENCED_PARAMETER( value );
	return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant & atom::CVariant::operator/=(const CVariant & value) 
{
    //TODO Auto-generated method stub
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			( *this ) /= casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			( *this ) /= casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			( *this ) /= casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			( *this ) /= casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			( *this ) /= casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			( *this ) /= casted;
		}
		break;
	}
    return( *this );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, I08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(I08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, I16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(I16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, I32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(I32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, I64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(I64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, U08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(U08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, U16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(U16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, U32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(U32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, U64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(U64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, float r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(float l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, double r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(double l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, const char * r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const char * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, const wchar_t * r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const wchar_t * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CVariant & l, const atom::CMemory & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator+(const atom::CMemory & l, const atom::CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result += r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, I08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(I08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, I16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(I16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, I32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(I32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, I64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(I64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, U08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(U08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, U16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(U16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, U32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(U32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, U64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(U64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, float r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(float l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, double r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(double l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, const char * r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const char * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, const wchar_t * r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const wchar_t * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CVariant & l, const atom::CMemory & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator-(const atom::CMemory & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result -= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, I08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(I08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, I16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(I16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, I32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(I32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, I64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(I64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, U08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(U08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, U16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(U16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, U32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(U32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, U64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(U64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, float r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(float l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, double r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(double l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, const char * r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const char * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, const wchar_t * r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const wchar_t * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CVariant & l, const atom::CMemory & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator*(const atom::CMemory & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result *= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, I08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(I08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, I16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(I16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, I32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(I32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, I64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(I64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, U08 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(U08 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, U16 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(U16 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, U32 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(U32 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, U64 r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(U64 l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, float r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(float l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, double r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(double l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, const char * r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const char * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, const wchar_t * r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const wchar_t * l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CVariant & l, const atom::CMemory & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CVariant atom::operator/(const atom::CMemory & l, const atom::CVariant & r)
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	result /= r;
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(I08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(I16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(I32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(I64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i < value );
		break;
	case VT_U_INT:
		result = ( variant.base.u < static_cast<U64>   (value) );
		break;
	case VT_FLOAT:
		result = ( variant.base.f < static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<I64>(*this) < value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(U08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(U16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(U32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(U64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i < static_cast<I64>   (value) );
		break;
	case VT_U_INT:
		result = ( variant.base.u < value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f < static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<U64>(*this) < value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(float value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) < static_cast<double>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(double value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i < value );
		break;
	case VT_U_INT:
		result = ( variant.base.u < value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f < value );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<double>(*this) < value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(const char * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const char * data = *this;
				if( data ) {
					result = ( strcmp(data, value) < 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(const wchar_t * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const wchar_t * data = *this;
				if( data ) {
					result = ( wcscmp(data, value) < 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(const CMemory & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( variant.type == VT_BLOCK )
	{
		if( variant.data.GetLength() == value.GetLength() ) {
			result = ( memcmp( variant.data, value, value.GetLength() ) < 0 );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<(const CVariant & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			result = (*this) < casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			result = (*this) < casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			result = (*this) < casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			result = (*this) < casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			result = (*this) < casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			result = (*this) < casted;
		}
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(I08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(I16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(I32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(I64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i <= value );
		break;
	case VT_U_INT:
		result = ( variant.base.u <= static_cast<U64>   (value) );
		break;
	case VT_FLOAT:
		result = ( variant.base.f <= static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<I64>(*this) <= value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(U08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(U16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(U32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(U64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i <= static_cast<I64>   (value) );
		break;
	case VT_U_INT:
		result = ( variant.base.u <= value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f <= static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<U64>(*this) <= value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(float value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) <= static_cast<double>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(double value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i <= value );
		break;
	case VT_U_INT:
		result = ( variant.base.u <= value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f <= value );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<double>(*this) <= value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(const char * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const char * data = *this;
				if( data ) {
					result = ( strcmp(data, value) <= 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(const wchar_t * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const wchar_t * data = *this;
				if( data ) {
					result = ( wcscmp(data, value) <= 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(const CMemory & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( variant.type == VT_BLOCK )
	{
		if( variant.data.GetLength() == value.GetLength() ) {
			result = ( memcmp( variant.data, value, value.GetLength() ) <= 0 );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator<=(const CVariant & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			result = (*this) <= casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			result = (*this) <= casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			result = (*this) <= casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			result = (*this) <= casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			result = (*this) <= casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			result = (*this) <= casted;
		}
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(I08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(I16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(I32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(I64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i > value );
		break;
	case VT_U_INT:
		result = ( variant.base.u > static_cast<U64>   (value) );
		break;
	case VT_FLOAT:
		result = ( variant.base.f > static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<I64>(*this) > value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(U08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(U16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(U32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(U64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i > static_cast<I64>   (value) );
		break;
	case VT_U_INT:
		result = ( variant.base.u > value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f > static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<U64>(*this) > value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(float value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) > static_cast<double>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(double value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i > value );
		break;
	case VT_U_INT:
		result = ( variant.base.u > value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f > value );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<double>(*this) > value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(const char * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const char * data = *this;
				if( data ) {
					result = ( strcmp(data, value) > 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(const wchar_t * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const wchar_t * data = *this;
				if( data ) {
					result = ( wcscmp(data, value) > 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(const CMemory & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( variant.type == VT_BLOCK )
	{
		if( variant.data.GetLength() == value.GetLength() ) {
			result = ( memcmp( variant.data, value, value.GetLength() ) > 0 );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>(const CVariant & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			result = (*this) > casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			result = (*this) > casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			result = (*this) > casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			result = (*this) > casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			result = (*this) > casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			result = (*this) > casted;
		}
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(I08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(I16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<I64>( value );
}
//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(I32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(I64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i >= value );
		break;
	case VT_U_INT:
		result = ( variant.base.u >= static_cast<U64>   (value) );
		break;
	case VT_FLOAT:
		result = ( variant.base.f >= static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<I64>(*this) >= value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(U08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(U16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(U32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(U64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i >= static_cast<I64>   (value) );
		break;
	case VT_U_INT:
		result = ( variant.base.u >= value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f >= static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<U64>(*this) >= value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(float value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) >= static_cast<double>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(double value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i >= value );
		break;
	case VT_U_INT:
		result = ( variant.base.u >= value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f >= value );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<double>(*this) >= value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(const char * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const char * data = *this;
				if( data ) {
					result = ( strcmp(data, value) >= 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(const wchar_t * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const wchar_t * data = *this;
				if( data ) {
					result = ( wcscmp(data, value) >= 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(const CMemory & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( variant.type == VT_BLOCK )
	{
		if( variant.data.GetLength() == value.GetLength() ) {
			result = ( memcmp( variant.data, value, value.GetLength() ) >= 0 );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator>=(const CVariant & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			result = (*this) >= casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			result = (*this) >= casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			result = (*this) >= casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			result = (*this) >= casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			result = (*this) >= casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			result = (*this) >= casted;
		}
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(I08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(I16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(I32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<I64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(I64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i != value );
		break;
	case VT_U_INT:
		result = ( variant.base.u != static_cast<U64>   (value) );
		break;
	case VT_FLOAT:
		result = ( variant.base.f != static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<I64>(*this) != value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(U08 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(U16 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(U32 value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<U64>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(U64 value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i != static_cast<I64>   (value) );
		break;
	case VT_U_INT:
		result = ( variant.base.u != value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f != static_cast<double>(value) );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<U64>(*this) != value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(float value) const 
{
    //TODO Auto-generated method stub
    return ( *this ) != static_cast<double>( value );
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(double value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( variant.type )
	{
	case VT_S_INT:
		result = ( variant.base.i != value );
		break;
	case VT_U_INT:
		result = ( variant.base.u != value );
		break;
	case VT_FLOAT:
		result = ( variant.base.f != value );
		break;
	case VT_BLOCK:
		// never equare;
		break;
	default:
		// convert and compare
		result = ( static_cast<double>(*this) != value );
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(const char * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const char * data = *this;
				if( data ) {
					result = ( strcmp(data, value) != 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(const wchar_t * value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( value )
	{
		switch( variant.type )
		{
		case VT_BLOCK:
			// never equare;
			break;
		default:
			{
				// convert and compare
				const wchar_t * data = *this;
				if( data ) {
					result = ( wcscmp(data, value) != 0 );
				}
			}
			break;
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(const CMemory & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	if( variant.type == VT_BLOCK )
	{
		if( variant.data.GetLength() == value.GetLength() ) {
			result = ( memcmp( variant.data, value, value.GetLength() ) != 0 );
		}
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CVariant::operator!=(const CVariant & value) const 
{
    //TODO Auto-generated method stub
	bool result = false;
	switch( value.variant.type )
	{
	case VT_S_INT:
		{
			I64 
			casted = value;
			result = (*this) != casted;
		}
		break;
	case VT_U_INT:
		{
			U64 
			casted = value;
			result = (*this) != casted;
		}
		break;
	case VT_FLOAT:
		{
			double 
			casted = value;
			result = (*this) != casted;
		}
		break;
	case VT_A_STR:
		{
			const char * 
			casted = value;
			result = (*this) != casted;
		}
		break;
	case VT_W_STR:
		{
			const wchar_t * 
			casted = value;
			result = (*this) != casted;
		}
		break;
	case VT_BLOCK:
		{
			CMemory 
			casted = value;
			result = (*this) != casted;
		}
		break;
	}
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const void * atom::CVariant::operator &() const 
{
    //TODO Auto-generated method stub
    const void * result = NULL;
    switch( variant.type )
    {
	case VT_S_INT:
    case VT_U_INT:
	case VT_FLOAT:
        result = & variant.base;
		break;
	case VT_A_STR:
	case VT_W_STR:
	case VT_BLOCK:
        result =   variant.data;
		break; 
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(I08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(I16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(I32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(I64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(U08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(U16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(U32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(U64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(float l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(double l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(const char * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(const wchar_t * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>(const CMemory & l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result > r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(I08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(I16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(I32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(I64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(U08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(U16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(U32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(U64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(float l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(double l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(const char * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(const wchar_t * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator>=(const CMemory & l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result >= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(I08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(I16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(I32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(I64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(U08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(U16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(U32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(U64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(float l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(double l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(const char * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(const wchar_t * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<(const CMemory & l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result < r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(I08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(I16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(I32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(I64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(U08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(U16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(U32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(U64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(float l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(double l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(const char * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(const wchar_t * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator<=(const CMemory & l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result <= r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(I08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(I16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(I32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(I64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(U08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(U16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(U32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(U64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(float l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(double l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(const char * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(const wchar_t * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator!=(const CMemory & l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result != r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(I08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(I16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(I32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(I64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(U08 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(U16 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(U32 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(U64 l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(float l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(double l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(const char * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(const wchar_t * l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::operator==(const CMemory & l, const CVariant & r) 
{
    //TODO Auto-generated method stub
	atom::CVariant result = l;
	return result == r;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U08 atom::CVariant::Parse(const char * value) 
{
    //TODO Auto-generated method stub
	U08 result = ST_TXT;
	if( value )
	{
		if( * value ) {
			result = ST_INT;
		}

		bool e_flag = false;
		bool d_flag = false;
		bool s_flag = false;

		while( * value )
		{
			char data = * value;

			// digital
			if( data >= '0' && data <= '9' ) {
				++ value; continue;
			}

			// sign
			if( (data == '+' || data == '-') && s_flag == false ) {
                s_flag = true;
				++ value; continue;
			}

			// float
			if( data == '.' && d_flag == false ) {
                d_flag = true;
				result = ST_FLT;
				++ value; continue;
			}

			// float 
			if( data == 'e' && e_flag == false ) {
				e_flag = true;
				result = ST_FLT;
				++ value; continue;
			}

			// character
			result = ST_TXT; break;
		}
	}
	return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
U08 atom::CVariant::Parse(const wchar_t * value) 
{
    //TODO Auto-generated method stub
	U08 result = ST_TXT;
	if( value )
	{
		if( * value ) {
			result = ST_INT;
		}

		bool e_flag = false;

		while( * value )
		{
			wchar_t data = * value;

			// digital
			if( data >= '0' && data <= '9' ) {
				++ value; continue;
			}

			// sign
			if( data == '+' || data == '-' ) {
				++ value; continue;
			}

			// float
			if( data == '.' ) {
				result = ST_FLT;
				++ value; continue;
			}

			// float 
			if( data == 'e' && e_flag == false ) {
				e_flag = true;
				result = ST_FLT;
				++ value; continue;
			}

			// character
			result = ST_TXT; break;
		}
	}
	return result;
}
