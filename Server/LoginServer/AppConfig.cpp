#include "StdAfx.h"
#include "AppConfig.h"
#include "../Utility/Markup.h"


// ��ȡ����
bool  LoadAppConfig(AppConfig& cfg)
{
    CMarkup xml;
    if (!xml.Load("login.config.xml"))
    {
        return false;
    }
    if (!xml.FindElem("config"))
    {
        return false;
    }
       
    // ���ݿ�����
    xml.IntoElem();
    if (xml.FindElem("database"))
    {
        xml.IntoElem();
        xml.FindElem("host");
        cfg.mysql_host = xml.GetData();
        xml.FindElem("port");
        cfg.mysql_port = std::stoi(xml.GetData());
        xml.FindElem("user");
        cfg.mysql_user = xml.GetData();
        xml.FindElem("pwd");
        cfg.mysql_pwd = xml.GetData();
        xml.FindElem("default");
        cfg.mysql_default = xml.GetData();
        xml.FindElem("charset");
        cfg.mysql_charset = xml.GetData();
        xml.FindElem("conn_pool_size");
        cfg.connection_pool_size = std::stoi(xml.GetData());
        xml.FindElem("max_idle_time");
        cfg.max_idle_time = std::stoi(xml.GetData());
        xml.OutOfElem();
    }
    xml.ResetMainPos();
    if (xml.FindElem("server"))
    {
        cfg.host = xml.GetAttrib("host");
        cfg.port = std::stoi(xml.GetAttrib("port"));
    }
    xml.ResetMainPos();
    if (xml.FindElem("atom"))
    {
        cfg.pool_size = std::stoi(xml.GetAttrib("pool_size"));
        cfg.thread_num = std::stoi(xml.GetAttrib("thread_num"));
    }
    xml.ResetMainPos();
    if (xml.FindElem("centerserver"))
    {
        cfg.rpc_host = xml.GetAttrib("host");
        cfg.rpc_port = std::stoi(xml.GetAttrib("port"));
    } 
    return true;
}
