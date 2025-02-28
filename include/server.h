#ifndef SERVER_H
#define SERVER_H

#include "net_common.h"

using namespace boost;
using tcp = asio::ip::tcp;
namespace fs = std::filesystem;


enum class conn_type {
    SENDING = 0,
    ACCEPTING = 1
};

struct session{

    session(asio::io_context& context);
    session();
    ~session();
    
    tcp::socket* receiver_socket;
    tcp::socket* sender_socket;
    std::string id;
    std::string filename;

};


class server{

public:

    server();

    void start();

    conn_type get_connection(session& socket);

    void begin_transfer(session& msession);

    void close_connections(session& sockets);

private:
    
    boost::system::error_code ec;
    asio::io_context context;
    tcp::endpoint endpoint;
    tcp::acceptor acceptor;
    std::vector<session> m_sessions;
    size_t session_count;
};


#endif