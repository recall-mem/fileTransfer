#ifndef NET_COMMON_H
#define NET_COMMON_H

#define ASIO_STANDALONE

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
#include <boost/system/error_code.hpp>
#include <boost/asio/deadline_timer.hpp>

#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <vector>
#include <string>
#include <memory>



namespace NET
{
    inline void print_error_and_exit(boost::system::error_code ec)
    {
        std::cout << "Error: " << ec.message() << std::endl;
        exit(EXIT_FAILURE);
    }


    inline void close_connection(boost::asio::ip::tcp::socket& socket)
    {
        std::cout << "Shutting down and closing socket" << std::endl;
        
        socket.shutdown(boost::asio::socket_base::shutdown_both);
        socket.close(); 
    }


    constexpr int DEFAULT_PORT = 6000;
    const std::string SERVER_IP("127.0.0.1");
};

#endif