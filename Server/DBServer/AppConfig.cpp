#include "StdAfx.h"
#include "AppConfig.h"
#include "../Utility/Markup.h"


// 读取配置信息
AppConfig    LoadAppConfig(const std::string& path)
{
    AppConfig cfg = {};
    CMarkup xml;
    CHECK(xml.Load(path)) << xml.GetError() << path;
    CHECK(xml.FindElem("config")) << "<config> not found.";
    
    // 数据库配置
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
    // RPC服务器配置
	xml.ResetMainPos();
    if (xml.FindElem("server"))
    {
        cfg.rpc_host = xml.GetAttrib("host");
        cfg.rpc_port = std::stoi(xml.GetAttrib("port").c_str());
    }
    return cfg;
}
