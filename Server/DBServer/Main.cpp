#include "DBServer.h"
#include <iostream>
#include <exception>
#include <filesystem>
#include <easylogging++.h>

using namespace std;

_INITIALIZE_EASYLOGGINGPP


// 初始化日志
void InitLogging(const string& conf_file, const string& dir)
{
    namespace fs = std::tr2::sys;
    fs::path path(dir);
    if (!fs::exists(path))
    {
        fs::create_directory(path);
    }
    el::Configurations conf(conf_file);
    el::Loggers::reconfigureAllLoggers(conf);
}


// 主入口
int main(int argc, const char* argv[])
{
    try
    {
        AppConfig cfg = LoadAppConfig("db.config.xml");

        // 初始化日志
        InitLogging(cfg.log_config_file, cfg.log_dir);  

        // 初始化RPC框架
        RCF::RcfInitDeinit rcfInit;

        DBServer::Create();
        DBServer& theApp = DBServer::GetInst();
        if (theApp.Init(cfg))
        {
            while(theApp.Run())
                ;
        }
        DBServer::Destroy();
    }
    catch(std::exception& ex)
    {
        LOG(FATAL) << ex.what();
    }
    catch(...)
    {
        LOG(FATAL) << "unexpected exception.\n";
    }    

    return 0;
}
