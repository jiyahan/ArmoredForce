#pragma once

#include <cstdint>
#include <string>



struct AppConfig
{
    std::string     mysql_host;             // ���ݿ�IP
    int32_t         mysql_port;             // ���ݿ�˿�
    std::string     mysql_user;             // ���ݿ��û���
    std::string     mysql_pwd;              // ��¼����
    std::string     mysql_default;          // Ĭ��schema
    std::string     mysql_charset;          // �������
    int32_t         connection_pool_size;   // ��󲢷�������
    int32_t         max_idle_time;          // ���ӿ���ʱ��

    std::string     host;               // TCP������������ַ
    int32_t         port;               // TCP�����˿�

    std::string     rpc_host;           // RPC��������ַ
    int32_t         rpc_port;           // RPC�������˿�

    int32_t         pool_size;      
    int32_t         thread_num;

    std::string     log_config_file;    // ��־����
    std::string     log_dir;            // ��־Ŀ¼ 
};


AppConfig    LoadAppConfig(const std::string& filepath);

