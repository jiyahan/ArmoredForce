#include "stdafx.h"
#include "AppConfig.h"
#include "Markup.h"
#include <glog/logging.h>


// ∂¡»°≈‰÷√
AppConfig    LoadAppConfig(const std::string& path)
{
    AppConfig cfg = {};

    CMarkup xml;
    CHECK(xml.Load(path)) << xml.GetError() << path;
    CHECK(xml.FindElem("config")) << "<config> not found.";
       
    //  ˝æ›ø‚≈‰÷√
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
    return cfg;
}
