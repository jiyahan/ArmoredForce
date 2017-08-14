#include "CenterServer.h"
#include <iostream>
#include <filesystem>
#include <RCF/RCF.hpp>
#include "easylogging++.h"
#include "Utility.h"
#include "AppConfig.h"

using namespace std;
namespace fs = std::tr2::sys;

_INITIALIZE_EASYLOGGINGPP



// ��ʼ����־
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


// �����
int main(int argc, const char* argv[])
{
    try
    {
        // ��ȡ��������
        AppConfig cfg = LoadAppConfig("center.config.xml");

        // ��ʼ����־����
        InitLogging(cfg.log_config_file, cfg.log_dir);

        // ��ʼ��RPC���
        RCF::RcfInitDeinit rcfInit;

        // ���з�����
        CenterServer& theApp = CenterServer::Create();        
        if (theApp.Init(cfg))
        {
            while (theApp.Run())
                ; 
        }
        CenterServer::Destroy();
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
