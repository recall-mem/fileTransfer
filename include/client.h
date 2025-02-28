#ifndef CLIENT_H
#define CLIENT_H

#include "net_common.h"
#include <filesystem>

using namespace boost;
namespace fs = std::filesystem;
using tcp = asio::ip::tcp;


class Client{

public:

    Client(const std::string id_, const std::string address_ = NET::SERVER_IP);
    Client(std::string id);
    Client();

    void send_file(const fs::path& FILEPATH) noexcept;
    
    /* If the FILEPATH did not given then fs::current_path() going to be used */
    void accept_file(std::string FILEPATH = "") noexcept;

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;

    
private:

    boost::system::error_code ec;
    asio::io_context context;
    tcp::endpoint endpoint;
    std::string address;
    tcp::socket socket;
    std::string id;


    void make_connection(std::string connection_type);
    void async_read(std::ofstream& OutFileStream);
};


#endif