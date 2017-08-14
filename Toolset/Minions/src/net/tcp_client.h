/**
 *  @file   tcp_client.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  һ��TCP���Ӷ���
 *
 */
#pragma once

#include <array>
#include <string>
#include <functional>
#include <boost/noncopyable.hpp>


enum {MAX_MSG_SIZE = 8192};
typedef std::array<uint8_t, MAX_MSG_SIZE>   buffer_type;

namespace asio_ip = boost::asio::ip;
namespace bs = boost::system;


class TcpClient;
typedef std::shared_ptr<TcpClient>  TcpClientPtr;


// ���ӣ���ȡ���ݺʹ������ʱ��Ļص�
typedef std::function<void (TcpClientPtr, const bs::error_code&)>       error_handler;
typedef std::function<void (TcpClientPtr, const std::string&, int16_t)> connect_handler;
typedef std::function<void (TcpClientPtr, size_t)>                      read_handler;


class TcpClient 
    :   public std::enable_shared_from_this<TcpClient>,
        boost::noncopyable
{
public:
    explicit TcpClient(boost::asio::io_service& io_service,
                       connect_handler on_connect,
                       read_handler on_read,
                       error_handler on_error);
    ~TcpClient();    

    // �첽����
    void    AsynConnect(const std::string& host, int16_t port);

    // �첽��������
    void    AsynWrite(const void* data, size_t bytes);

    // �첽��ȡ����
    void    AsynRead();

    // �ر�����
    void    AsynClose();

    asio_ip::tcp::socket& GetSocket() {return socket_;}

    const buffer_type&  GetDataBuffer() const {return data_buffer_;}

private:
    asio_ip::tcp::socket    socket_;        // �׽��ֶ���
    buffer_type             data_buffer_;   // ��ȡ������

    size_t      write_bytes_;

    error_handler       on_error_;      // ����ص�
    connect_handler     on_connect_;    // ���ӻص�
    read_handler        on_read_;       // ��ȡ�ص�
};