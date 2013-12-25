#include "AppConfig.h"
#include "../Utility/Markup.h"


// 读取配置信息
AppConfig    LoadAppConfig(const std::string& path)
{
    AppConfig cfg = {};
    CMarkup xml;
    CHECK(xml.Load(path)) << xml.GetError() << path;
    CHECK(xml.FindElem("config")) << "<config> not found.";
       
    xml.IntoElem();
    if (xml.FindElem("server"))
    {
        cfg.rpc_host = xml.GetAttrib("host");
        cfg.rpc_port = std::stoi(xml.GetAttrib("port"));
    }
	xml.ResetMainPos();
    if (xml.FindElem("dbserver"))
    {
        cfg.rpc_db_host = xml.GetAttrib("host");
        cfg.rpc_db_port = std::stoi(xml.GetAttrib("port"));
    }
    xml.ResetMainPos();
    if (xml.FindElem("atom"))
    {
        cfg.pool_size = std::stoi(xml.GetAttrib("pool_size"));
        cfg.thread_num = std::stoi(xml.GetAttrib("thread_num"));
    }

    return cfg;
}
