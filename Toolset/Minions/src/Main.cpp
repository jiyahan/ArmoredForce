#include <iostream>
#include <exception>
#include <filesystem>
#include <glog/logging.h>
#include "Utility.h"
#include "Minons.h"
#include "Config.h"

using namespace std;
namespace fs = std::tr2::sys;

// 初始化日志
void InitLogging(int argc, const char* argv[])
{
    fs::path dir("log");
    if (!fs::exists(dir))
    {
        fs::create_directory(dir);
    }

    google::InitGoogleLogging(argv[0]);

    FLAGS_log_dir = dir.string();
    FLAGS_alsologtostderr = true;
}


int main(int argc, const char* argv[])
{
    try
    {
        // 初始化日志 
        InitLogging(argc, argv);         

        // 读取配置
        const Config& cfg = LoadAppConfig("minion.config.xml");

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
        LOG(ERROR) << ex.what();
    }
    catch(...)
    {
        LOG(FATAL) << "unexpected exception.\n";
    }

    google::ShutdownGoogleLogging();

    return 0;
}