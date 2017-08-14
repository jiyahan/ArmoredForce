/**
 *  @file   minion_app.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  �������еĻ����˶���
 *
 */

#pragma once

#include <string>
#include <unordered_map>
#include <boost/noncopyable.hpp>
#include <boost/asio.hpp>
#include "Singleton.h"
#include "minion.h"
#include "script/script_rt.h"


class MinionApp : public Singleton<MinionApp>
{
public:
    MinionApp();
    ~MinionApp();

    bool Init(const std::string& file);

    // ��ʼ����
    bool Run();

    // �����˶���Ĵ���������
    MinionPtr   CreateMinion(const std::string& host, int16_t port);
    void        DestroyMinion(Minion* ptr);

    boost::asio::io_service&    GetIOService() {return io_service_;}

public:
    // �����¼��ص�
    void    OnTcpError(size_t, TcpClientPtr, const bs::error_code&);
    void    OnTcpConnect(size_t, TcpClientPtr, const std::string&, int16_t);
    void    OnTcpRead(size_t, TcpClientPtr, size_t);

private:
    // �ṩI/O�������ɶ˿ڶ���(Windowsʵ��)
    boost::asio::io_service     io_service_;

    // lua�����
    ScriptRuntime   script_;

    // ���еĻ�����
    std::unordered_map<size_t, MinionPtr>   minion_list_;

    // �����˱�ʶ��
    size_t     current_id_; 
};

// ����һ��io_service����
inline boost::asio::io_service&  GetIOService()
{
    return MinionApp::GetInst().GetIOService();
}
