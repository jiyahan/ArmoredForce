#include "CXmlElementNode.h"
#include "CXmlElementPtr.h"
#include "../../pattern/life/CInstanceLife.h"
#include "../tool/CInstanceUtility.h"
#include "../tool/CInterface.h"
#include "../../enumeration/OBJECT_ID.h"
#include "../../enumeration/INTERFACE_ID.h"


atom::CXmlElementNode::CXmlElementNode() : 
nest(NULL),self(NULL),node(0)
{
}

atom::CXmlElementNode::~CXmlElementNode() 
{
	Shutdown();
}

atom::CDefinedXmlNode * atom::CXmlElementNode::Search(CDefinedXmlNode * parent, const char * tag_name, bool recursive) 
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

int atom::CXmlElementNode::IncRef() 
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

int atom::CXmlElementNode::DecRef() 
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

int atom::CXmlElementNode::GetRef() 
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

atom::IInterface * atom::CXmlElementNode::QueryInterface(U32 iid) 
{
    IInterface * result = NULL;
    if( nest && iid ) {
        result = nest -> QueryInterface( iid );
    }
    return result;
}

void atom::CXmlElementNode::SetNest(IInterface * value) 
{
    if( value ) nest = value;
}

bool atom::CXmlElementNode::Initiate(U64 parent, CDefinedXmlNode * object) 
{
	Shutdown();

	self = object;
	node = parent;

	if( node ) CInstanceLife::GetInstance() -> Increase( node );
    return true;
}

void atom::CXmlElementNode::Shutdown() 
{
	if( node ) CInstanceLife::GetInstance() -> Decrease( node );
	self = NULL; node = 0;
}

bool atom::CXmlElementNode::Append(const char * tag_name) 
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

bool atom::CXmlElementNode::Append(const char * tag_name, CXmlElementPtr & output) 
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

bool atom::CXmlElementNode::Remove(CXmlElementPtr & child) 
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

atom::CXmlElementPtr atom::CXmlElementNode::Search(const char * tag_name, bool recursive) 
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

atom::CXmlElementPtr atom::CXmlElementNode::Next(const char * tag_name) 
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
				result -> Initiate( node, next );
			}
		}
	}
	return result;
}

atom::CDefinedXmlNode * atom::CXmlElementNode::Node() 
{
	return self;
}

const char * atom::CXmlElementNode::GetName() 
{
	char* result = NULL;
	if( self )
	{
		result = self -> name();
	}
	return result;
}

const char * atom::CXmlElementNode::GetText() 
{
	char* result = NULL;
	if( self )
	{
		result = self -> value();
	}
	return result;
}

void atom::CXmlElementNode::SetText(const char * value) 
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

const char * atom::CXmlElementNode::StrAttribute(const char * name) 
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

I64 atom::CXmlElementNode::IntAttribute(const char * name) 
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

double atom::CXmlElementNode::FltAttribute(const char * name) 
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

bool atom::CXmlElementNode::SetAttribute(const char * name, const char * data) 
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

bool atom::CXmlElementNode::SetAttribute(const char * name, I64 value) 
{
	char buffer[64];
	sprintf( buffer, "%lli", value );
	return SetAttribute( name, buffer );
}

bool atom::CXmlElementNode::SetAttribute(const char * name, double value) 
{
	char buffer[64];
	sprintf( buffer, "%f", value );
	return SetAttribute( name, buffer );
}
