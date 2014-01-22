#include "CXmlDocumentNode.h"
#include "CXmlElementPtr.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../tool/CInstanceUtility.h"
#include "../tool/CInterface.h"
#include "../../log/CLog.h"
#include "../../os/file/CFile.h"
#include "../../enumeration/OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CXmlDocumentNode::CXmlDocumentNode() : 
nest(NULL),self(NULL)
{
	self = new rapidxml::xml_document<>;
}

atom::CXmlDocumentNode::~CXmlDocumentNode() 
{
	Shutdown();
}

atom::CDefinedXmlNode * atom::CXmlDocumentNode::Search(CDefinedXmlNode * parent, const char * tag_name, bool recursive) 
{
	CDefinedXmlNode * result = NULL;
	if( parent && tag_name )
	{
		result = parent -> first_node( tag_name );

		// 如果遍历没有找到，那么进行深度遍历，继续查找。
		if( result == NULL && recursive )
		{
			CDefinedXmlNode * child = parent -> first_node();
			for( ; child; child = child -> next_sibling() )
			{
				if( ( result = Search(child, tag_name, recursive) ) != NULL ) break;
			}
		}
	}
	return result;
}

int atom::CXmlDocumentNode::IncRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> IncRef();
        }
    }
    return result;
}

int atom::CXmlDocumentNode::DecRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> DecRef();
        }
    }
    return result;
}

int atom::CXmlDocumentNode::GetRef() 
{
    int result = 0;
    if( nest )
    {
        IReferencedInterface * refered = 
            dynamic_cast<IReferencedInterface *>( nest );
        if( refered ) {
            result = refered -> GetRef();
        }
    }
    return result;
}

atom::IInterface * atom::CXmlDocumentNode::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CXmlDocumentNode::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CXmlDocumentNode::Initiate(U64 parent, CDefinedXmlNode * object) 
{
	UNREFERENCED_PARAMETER( parent );
	UNREFERENCED_PARAMETER( object );
    return true;
}

void atom::CXmlDocumentNode::Shutdown() 
{
	if( self )
	{
		rapidxml::xml_document<>*
			doc = static_cast<rapidxml::xml_document<>*>( self );
		SAFE_DELETE( doc ); self = NULL;
	}
}

bool atom::CXmlDocumentNode::Append(const char * tag_name) 
{
	bool result = false;
	if( self && tag_name )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc )
		{
			rapidxml::xml_node<>* chd = doc -> 
				allocate_node( rapidxml::node_element, doc -> allocate_string(tag_name) );
			if( chd )
			{
				self -> append_node( chd );
				result = true;
			}
		}
	}
	return result;
}

bool atom::CXmlDocumentNode::Append(const char * tag_name, CXmlElementPtr & output) 
{
	bool result = false;
	if( self && tag_name )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc )
		{
			rapidxml::xml_node<>* chd = doc -> 
				allocate_node( rapidxml::node_element, doc -> allocate_string(tag_name) );
			if( chd )
			{
				self -> append_node( chd );
				result = true;
				output = CInstanceUtility::CreateInstance( OID_XML_ELEMENT );
				if( output ) {
					output -> Initiate( CInstanceUtility::GetInstanceName(nest), chd );
				}
			}
		}
	}
	return result;
}

bool atom::CXmlDocumentNode::Remove(CXmlElementPtr & child) 
{
	bool result = false;
	if( self && child )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc ) 
		{
			result = true;
			self -> remove_node( child -> Node() ); 

			CInterface<IInstanceLife> segment;
			if( segment.Mount(child, IID_INSTANCE_LIFE) ) {
				segment -> Shutdown();
			}
		}
	}
	return result;
}

atom::CXmlElementPtr atom::CXmlDocumentNode::Search(const char * tag_name, bool recursive) 
{
	CXmlElementPtr result;
	if( nest && self && tag_name )
	{
		CDefinedXmlNode * child = Search( self, tag_name, recursive );
		if( child )
		{
			result = CInstanceUtility::CreateInstance( OID_XML_ELEMENT );
			if( result ) {
				result -> Initiate( CInstanceUtility::GetInstanceName(nest), child );
			}
		}
	}
	return result;
}

atom::CXmlElementPtr atom::CXmlDocumentNode::Next(const char * tag_name) 
{
	CXmlElementPtr result;
	if( tag_name && self )
	{
		rapidxml::xml_node<>* next = 
			self -> next_sibling( tag_name );
		if( next )
		{
			result = CInstanceUtility::CreateInstance( OID_XML_ELEMENT );
			if( result ) {
				result -> Initiate( 0, next );
			}
		}
	}
	return result;
}

atom::CDefinedXmlNode * atom::CXmlDocumentNode::Node() 
{
	return self;
}

const char * atom::CXmlDocumentNode::GetName() 
{
	char* result = NULL;
	if( self )
	{
		result = self -> name();
	}
	return result;
}

const char * atom::CXmlDocumentNode::GetText() 
{
	char* result = NULL;
	if( self )
	{
		result = self -> value();
	}
	return result;
}

void atom::CXmlDocumentNode::SetText(const char * value) 
{
	if( self && value )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc )
		{
			bool result = false;
			self -> value( doc -> allocate_string(value) ); 
				
			for( rapidxml::xml_node<>*
				data = self -> first_node(); data; data = data -> next_sibling() ) 
			{
				if( data -> type() == rapidxml::node_data ) {
					data -> value( doc -> allocate_string(value) ); 
					result = true; break;
				}
			}

			if( !result )
			{
				rapidxml::xml_node<>* data = 
					doc -> allocate_node( rapidxml::node_data, NULL, 
					doc -> allocate_string(value) );
				if( data ) {
					self -> append_node( data );
				}
			}
		}
	}
}

const char * atom::CXmlDocumentNode::StrAttribute(const char * name) 
{
    static char null_str[] = "";
	
    char * result = null_str;
	if( self && name )
	{
		rapidxml::xml_attribute<>*
			attr = self -> first_attribute( name );
		if( attr ) {
			result = attr -> value();
		}
	}
	return result; 
}

I64 atom::CXmlDocumentNode::IntAttribute(const char * name) 
{
	I64 result = 0;
	if( self && name )
	{
		rapidxml::xml_attribute<>*
			attr = self -> first_attribute( name );
		if( attr ) 
		{
			#if defined(_WIN32)
			result = _atoi64( attr -> value() );
			#endif

			#if defined(__linux) || defined(__APPLE__)
			result = atoll( attr -> value() );
			#endif
		}
	}
	return result;
}

double atom::CXmlDocumentNode::FltAttribute(const char * name) 
{
	double result = 0.0;
	if( self && name )
	{
		rapidxml::xml_attribute<>*
			attr = self -> first_attribute( name );
		if( attr ) {
			result = atof( attr -> value() );
		}
	}
	return result;
}

bool atom::CXmlDocumentNode::SetAttribute(const char * name, const char * data) 
{
	bool result = false;
	if( self && name && data )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc )
		{
			rapidxml::xml_attribute<>*
				old_attr = self -> first_attribute( name );
			if( old_attr ) {
                self -> remove_attribute( old_attr );
			}

			rapidxml::xml_attribute<>* attr =
				doc -> allocate_attribute( 
				doc -> allocate_string(name), 
				doc -> allocate_string(data) );
			if( attr ) {
				self -> append_attribute( attr ); 
				result = true;
			}
		}
	}
	return result;
}

bool atom::CXmlDocumentNode::SetAttribute(const char * name, I64 value) 
{
	char buffer[64];
	sprintf( buffer, "%lli", value );
	return SetAttribute( name, buffer );
}

bool atom::CXmlDocumentNode::SetAttribute(const char * name, double value) 
{
	char buffer[64];
	sprintf( buffer, "%f", value );
	return SetAttribute( name, buffer );
}

bool atom::CXmlDocumentNode::Load(const char * name) 
{
	bool result = false;
	if( name )
	{
		CFile file( name );
		if( file.Open() )
		{
			size_t length = static_cast<size_t>( file.Length() );
			CMemory data;
			
			if( data.Alloc(length) )
			{
				CInterface<IFileStream> segment;
				if( segment.Mount(& file, IID_FILE_STREAM) ) 
				{
					result = ( length == 
						segment -> Read(data, length) );
					data.SetLength( length );
				}
			}

			if( result ) {
				result = Load( data );
			}

			file.Close();
		}
	}
    return result;
}

bool atom::CXmlDocumentNode::Load(CMemory & data) 
{
	bool result = false;
	if( self && data && data.GetLength() )
	{
        try 
        {
			a_string value; 
			value.assign( data.Query<char>(), data.GetLength() );

			rapidxml::xml_document<>* doc = self -> document();
			if( doc ) {
				doc -> parse<rapidxml::parse_declaration_node>( 
					doc -> allocate_string( value.c_str(), value.length() + 1 ) ); 
				result = true;
			}
        }
        catch(...)
        {
			CLog log;
			log << "Load XML:" 
				<< line_end << data.Query<char>() 
				<< line_end << "FAILED!" << end_error;
            result = false;
        }
	}
	return result;
}

bool atom::CXmlDocumentNode::Save(const char * name) 
{
	bool result = false;
	if( name )
	{
		CFile file( name );
		if( file.Open() )
		{
			CMemory data; Save( data );

			if( data )
			{
				CInterface<IFileStream> segment;
				if( segment.Mount(& file, IID_FILE_STREAM) ) 
				{
					segment -> Write( data, data.GetLength() );
					result = true;
				}
			}

			file.Close();
		}
	}
    return result;
}

bool atom::CXmlDocumentNode::Save(CMemory & data) 
{
	bool result = false;
	if( self )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc )
		{
			a_string content;
			rapidxml::print( std::back_inserter(content), *doc, 0 );

			if( data.Alloc( content.length() + 1 ) ) 
			{
				strcpy( data.Query<char>(), content.c_str() ); 
                data.SetLength( content.length() );
				result = true;
			}
		}
	}
	return result;
}

void atom::CXmlDocumentNode::SetDeclaration(const char * version, const char * encoding) 
{
	if( self && version && encoding )
	{
		rapidxml::xml_document<>* doc = self -> document();
		if( doc )
		{
			bool result = false;
			for( rapidxml::xml_node<>* 
				next = doc -> first_node(); next; next = next -> next_sibling() )
			{
				if( next -> type() == rapidxml::node_declaration )
				{
					rapidxml::xml_attribute<>* attr_1 = 
						next -> first_attribute( "version" );
					if( attr_1 ) {
						attr_1 -> value( doc -> allocate_string(version) );
					} else {
						next -> append_attribute(
							doc -> allocate_attribute(
							doc -> allocate_string("version"), 
							doc -> allocate_string(version) ) );
					}

					rapidxml::xml_attribute<>* attr_2 = 
						next -> first_attribute( "encoding" );
					if( attr_2 ) {
						attr_2 -> value( doc -> allocate_string(encoding) );
					} else {
						next -> append_attribute(
							doc -> allocate_attribute(
							doc -> allocate_string("encoding"), 
							doc -> allocate_string(encoding) ) );
					}
					result = true; break;
				}
			}

			if( result == false )
			{
				rapidxml::xml_node<>* declare = 
					doc -> allocate_node( rapidxml::node_declaration );
				if( declare )
				{
					declare -> append_attribute( 
						doc -> allocate_attribute(
						doc -> allocate_string("version"), 
						doc -> allocate_string("1.0") ) );

					declare -> append_attribute( 
						doc -> allocate_attribute(
						doc -> allocate_string("encoding"), 
						doc -> allocate_string("GB2312") ) );

					doc -> append_node( declare );
				}
			}
		}
	}
}
