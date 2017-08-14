#pragma once

#include <unordered_map>
#include <RCF/RCF.hpp>
#include "AppConfig.h"
#include "CenterRpcService.h"
#include "../Utility/Singleton.h"


//
// ���ķ�����
//
class CenterServer : public Singleton<CenterServer>
{
public:
    CenterServer();
    ~CenterServer();

    //��ʼ��
    bool    Init();

    // �ͷ���Դ
    void    Release();

    // ���з�����
    bool    Run();

    // ֹͣ������
    void    Stop();

private:
    AppConfig           config_;        // ����
    CenterRpcService    rpc_impl_;
    std::shared_ptr<RCF::RcfServer>     rpc_server_;
};
