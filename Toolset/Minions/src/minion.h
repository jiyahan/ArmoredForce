/**
 *  @file   minion.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  ���������˶���
 *
 */

#pragma once

#include <memory>
#include "net/tcp_client.h"

namespace electron {class CMessage;}

class Minion : boost::noncopyable
{
public:
    explicit Minion(TcpClientPtr ptr);
    ~Minion();

    // ������Ϣ��������
    void    Write(electron::CMessage* msg);

    // �����ȡ��Ϣ����
    void    Read();

    size_t  GetID() const {return id_;}
    void    SetID(size_t id) {id_ = id;}

private:
    // Ψһ��ʶ��
    size_t          id_;

    // TCP����
    TcpClientPtr    tcp_conn_;
};
