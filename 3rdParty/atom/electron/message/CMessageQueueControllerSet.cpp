#include "CMessageQueueControllerSet.h"
//Begin section for file CMessageQueueControllerSet.cpp
//TODO: Add definitions that you want preserved
//End section for file CMessageQueueControllerSet.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessageQueueControllerSet::CMessageQueueControllerSet() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
electron::CMessageQueueControllerSet::~CMessageQueueControllerSet() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessageQueueControllerSet::Insert(CMessage * message) 
{
    //TODO Auto-generated method stub
    if( !message ) return false;

	section.Enter(); queue.push_back( message ); 
    section.Leave();
	return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool electron::CMessageQueueControllerSet::Obtain(CMessageQueueControllerSetBind & out) 
{
    //TODO Auto-generated method stub
    // ׼���������У������������еĴ�С���Ƶ�100����
    CMessageQueueControllerSetBind swap; 
    swap.reserve( 128 );

    // ���������е���Ϣ��������Ϣ��������������ڣ�
    section.Enter(); swap.swap( queue );
	section.Leave();

    size_t reserve = out.size() + swap.size();
    reserve = ( reserve / 128 + 1 ) * 128;

    out.reserve( reserve );
    std::copy( swap.begin(), swap.end(), back_inserter(out) );
	return true;
}
