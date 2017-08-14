#include "CCodePage.h"


atom::CCodePage::CCodePage() 
{
}

atom::CCodePage::~CCodePage() 
{
}

bool atom::CCodePage::Initiate() 
{
    a_string name;
    section.Enter();
        
    // ����
    name = "GB2312";
    related[name] = 936;
        
    // ��������
    name = "BIG5";
    related[name] = 950;
        
    // �����ַ�
    name = "SHIFT_JIS";
    related[name] = 932;
        
    // �����ַ�
    name = "EUC-JP";
    related[name] = 932;

    // ��������
    name = "HZ-GB-2312";
    related[name] = 52936;
        
    // ��׼��ŷ�ַ�
    name = "us-ascii";
    related[name] = 1252;

    name = "ascii";
    related[name] = 1252;

    section.Leave();
    return true;
}

void atom::CCodePage::Shutdown() 
{
    section.Enter();
    related.clear();
    section.Leave();
}

I32 atom::CCodePage::CodePage(const char * value) 
{
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

const char * atom::CCodePage::GetLocal() 
{
    return DEFAULT_CODEPAGE;
}
