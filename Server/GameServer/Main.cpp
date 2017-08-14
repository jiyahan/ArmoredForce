#include "stdafx.h"
#include "GameServer.h"
#include <iostream>
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


// �����
int main(int argc, const char* argv[])
{
    try
    {
        // ��ȡ����
        AppConfig cfg = LoadAppConfig("game.config.xml");

        // ��ʼ����־
        InitLogging(cfg.log_config_file, cfg.log_dir);                

        // ��ʼ��RPC���
        RCF::RcfInitDeinit rcfInit;

        // ��ʼ��atom
        AtomAutoInit atomInit(cfg.pool_size, cfg.thread_num);

        // ���з�����
        auto& theApp = GameServer::Create();
        if (theApp.Init(cfg))
        {
            while (theApp.Run())
                ;
        }
        GameServer::Destroy();
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
