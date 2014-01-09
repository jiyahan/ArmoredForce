#include <iostream>
#include <exception>
#include <filesystem>
#include "Utility.h"
#include "Minons.h"
#include "Config.h"

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


int main(int argc, const char* argv[])
{
    try
    {
        // 读取配置
        Config cfg = LoadAppConfig("minion.config.xml");

        // 初始化日志 
        InitLogging(cfg.log_config_file, cfg.log_dir);           
        
        // 初始化atom
        AtomAutoInit init(cfg.pool_size, cfg.thread_num);

        // 运行
        Minions&  app = Minions::GetInstance();
        if (app.Init(cfg))
        {
            while (app.Run())
                ;
            app.Release();
        }
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