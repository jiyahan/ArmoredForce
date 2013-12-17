#include "stdafx.h"
#include "AppConfig.h"
#include "../Utility/Markup.h"


// ∂¡»°≈‰÷√–≈œ¢
bool  LoadAppConfig(AppConfig& cfg)
{
    CMarkup xml;
    if (!xml.Load("center.config.xml"))
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
        cfg.rpc_host = xml.GetAttrib("host");
        cfg.rpc_port = std::stoi(xml.GetAttrib("port"));
    }
	xml.ResetMainPos();
    if (xml.FindElem("dbserver"))
    {
        cfg.rpc_db_host = xml.GetAttrib("host");
        cfg.rpc_db_port = std::stoi(xml.GetAttrib("port"));
    }
    return true;
}
