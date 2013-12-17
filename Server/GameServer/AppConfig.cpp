#include "stdafx.h"
#include "AppConfig.h"
#include "../Utility/Markup.h"


bool  LoadAppConfig(AppConfig& cfg)
{
    CMarkup xml;
    if (!xml.Load("game.config.xml"))
    {
        return false;
    }
    if (!xml.FindElem("config"))
    {
        return false;
    }
       
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
    return true;
}
