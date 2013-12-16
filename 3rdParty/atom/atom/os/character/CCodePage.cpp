#include "CCodePage.h"
//Begin section for file CCodePage.cpp
//TODO: Add definitions that you want preserved
//End section for file CCodePage.cpp


//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CCodePage::CCodePage() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
atom::CCodePage::~CCodePage() 
{
    //TODO Auto-generated method stub
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
bool atom::CCodePage::Initiate() 
{
    //TODO Auto-generated method stub
    a_string name;
    section.Enter();
        
    // 中文
    name = "GB2312";
    related[name] = 936;
        
    // 繁体中文
    name = "BIG5";
    related[name] = 950;
        
    // 日文字符
    name = "SHIFT_JIS";
    related[name] = 932;
        
    // 日文字符
    name = "EUC-JP";
    related[name] = 932;

    // 简体中文
    name = "HZ-GB-2312";
    related[name] = 52936;
        
    // 标准西欧字符
    name = "us-ascii";
    related[name] = 1252;

    name = "ascii";
    related[name] = 1252;

    section.Leave();
    return true;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
void atom::CCodePage::Shutdown() 
{
    //TODO Auto-generated method stub
    section.Enter();
    related.clear();
    section.Leave();
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
I32 atom::CCodePage::CodePage(const char * value) 
{
    //TODO Auto-generated method stub
    I32 result = DEFAULT_CODEPAGE_ID; 
    if( value )
    {
        section.Enter();
        CCodePageBind::iterator it = related.find( value );
        if( it != related.end() ) {
            result = it -> second;
        }
        section.Leave();
    }
    return result;
}

//@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
const char * atom::CCodePage::GetLocal() 
{
    //TODO Auto-generated method stub
    return DEFAULT_CODEPAGE;
}
