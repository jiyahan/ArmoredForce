#include "stdafx.h"
#include "AppConfig.h"
#include "Markup.h"
#include <glog/logging.h>


AppConfig  LoadAppConfig(const std::string& path)
{
    AppConfig cfg = {};
    
    CMarkup xml;
    CHECK(xml.Load(path)) << xml.GetError() << path;
    CHECK(xml.FindElem("config")) << "<config> not found.";
       
    xml.IntoElem();
    if (xml.FindElem("server"))
    {
        cfg.host = xml.GetAttrib("host");
        cfg.port = std::stoi(xml.GetAttrib("port"));
    }
    xml.ResetMainPos();
    if (xml.FindElem("centerserver"))
    {
        cfg.rpc_center_host = xml.GetAttrib("host");
        cfg.rpc_center_port = std::stoi(xml.GetAttrib("port"));
    }
    xml.ResetMainPos();
    if (xml.FindElem("atom"))
    {
        cfg.pool_size = std::stoi(xml.GetAttrib("pool_size"));
        cfg.thread_num = std::stoi(xml.GetAttrib("thread_num"));
    }
    return cfg;
}
