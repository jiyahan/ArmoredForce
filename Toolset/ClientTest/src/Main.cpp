#include <iostream>
#include <exception>
#include <filesystem>
#include "Utility.h"
#include "ClientApp.h"
#include "Config.h"

using namespace std;


_INITIALIZE_EASYLOGGINGPP



int main(int argc, const char* argv[])
{
    try
    {
        // 读取配置
        Config cfg = LoadAppConfig("client.config.xml");      
        
        // 初始化atom
        AtomAutoInit init(cfg.pool_size, cfg.thread_num);

        // 运行
        ClientApp::Create(cfg);
        if (GetApp().Init())
        {
            while (GetApp().Run())
                ;
        }
        ClientApp::Destroy();
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