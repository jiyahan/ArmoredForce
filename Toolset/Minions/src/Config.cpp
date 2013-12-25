#include "Config.h"
#include <Markup.h>

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

    return cfg;
}