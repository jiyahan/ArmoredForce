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
#include "minion.h"
#include "script/script_rt.h"



class MinionApp : boost::noncopyable
{
public:
    MinionApp();
    ~MinionApp();

    // ��ʼ����
    bool Start(const std::string& script);

    // �����˶���Ĵ���������
    Minion* CreateMinion(const std::string& host, int16_t port);
    void    DestroyMinion(Minion* ptr);

public:
    // �����¼��ص�
    void    OnTcpError(size_t, TcpClientPtr, const bs::error_code&);
    void    OnTcpConnect(size_t, TcpClientPtr, const std::string&, int16_t);
    void    OnTcpRead(size_t, TcpClientPtr, size_t);

private:
    // �����˱�ʶ��
    size_t     current_id_; 

    // ���еĻ�����
    std::unordered_map<size_t, Minion*>   minion_list_;

    // lua�����
    ScriptRuntime   script_;

    // io_service����(��I/O Completion Port)
    boost::asio::io_service     io_service_;
};

bool        CreateApp();
MinionApp&  GetApp();
void        DestroyApp();
