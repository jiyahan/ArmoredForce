#pragma once

#include <RCF/RCF.hpp>

//
// RPC�ӿڶ���
//  DBServerʵ�����½ӿ�
//  CenterServerʹ����Щ�ӿ�
//

RCF_BEGIN(IDBRpcService, "IDBRpcService")    
    // ��¼
    RCF_METHOD_R2(int, QueryLogin, const std::string&, const std::string&)      

    // ע��
    RCF_METHOD_R2(int, RegisterUser, const std::string&, const std::string&)
RCF_END(IDBRpcService)
