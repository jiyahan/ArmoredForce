#include "stdafx.h"
#include "LoginServer.h"
#include <filesystem>
#include <easylogging++.h>
#include <RCF/RCF.hpp>
#include "AtomAutoInit.h"
#include "AppConfig.h"


using namespace std;


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


int main(int argc, const char* argv[])
{
    char buffer[200];
    sprintf_s(buffer, 200, "%d%c", 30, 'c');
    try
    {
        AppConfig cfg = LoadAppConfig("login.config.xml");

        // ��ʼ����־
        InitLogging(cfg.log_config_file, cfg.log_dir);        

        // ��ʼ��RPC���
        RCF::RcfInitDeinit rcfInit;

        // ��ʼ��Atom
        AtomAutoInit  atomInit(cfg.pool_size, cfg.thread_num);

        // ���з�����
        auto& theApp = LoginServer::Create(cfg);        
        if (theApp.Init())
        {
            while (theApp.Run())
                ;
        }
        LoginServer::Destroy();
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

