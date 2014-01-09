#include "AppConfig.h"
#include "Markup.h"
#include <easylogging++.h>

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
        cfg.mysql_host = xml.GetAttrib("host");
        cfg.mysql_port = std::stoi(xml.GetAttrib("port"));
        cfg.mysql_user = xml.GetAttrib("user");;
        cfg.mysql_pwd = xml.GetAttrib("pwd");
        cfg.mysql_default = xml.GetAttrib("default");
        cfg.mysql_charset = xml.GetAttrib("charset");
        cfg.connection_pool_size = std::stoi(xml.GetAttrib("conn_pool_size"));
        cfg.max_idle_time = std::stoi(xml.GetAttrib("max_idle_time"));
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
    xml.ResetMainPos();
    if (xml.FindElem("log"))
    {
        cfg.log_config_file = xml.GetAttrib("config_file");
        cfg.log_dir = xml.GetAttrib("dir");
    }
    return std::move(cfg);
}
