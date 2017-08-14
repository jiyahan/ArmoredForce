#pragma once

#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "DBRpcService.h"
#include "../Utility/Singleton.h"

//
// ���ݿ������
//
class DBServer : public Singleton<DBServer>
{
public:
    DBServer();
    ~DBServer();

    // ��ʼ��
    bool    Init();

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

private:
    AppConfig           config_;
    
    DBRpcService        rpc_impl_;
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};