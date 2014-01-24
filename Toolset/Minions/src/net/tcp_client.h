/**
 *  @file   tcp_client.h
 *  @author chenqiang01@7aurora.com
 *  @date   Jan 21, 2014
 *  @brief  一个TCP连接对象
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


// 连接，读取数据和错误产生时候的回调
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

    // 异步请求
    void    AsynConnect(const std::string& host, int16_t port);

    // 异步发送数据
    void    AsynWrite(const void* data, size_t bytes);

    // 异步读取数据
    void    AsynRead();

    // 关闭连接
    void    AsynClose();

    asio_ip::tcp::socket& GetSocket() {return socket_;}

    const buffer_type&  GetDataBuffer() const {return data_buffer_;}

private:
    asio_ip::tcp::socket    socket_;        // 套接字对象
    buffer_type             data_buffer_;   // 读取缓冲区

    size_t      write_bytes_;

    error_handler       on_error_;      // 错误回调
    connect_handler     on_connect_;    // 连接回调
    read_handler        on_read_;       // 读取回调
};