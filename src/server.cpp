#include "net_common.h"
#include "server.h"
#include <map>

namespace asio = boost::asio;
namespace fs = std::filesystem;
using tcp = asio::ip::tcp;




session::session(asio::io_context& context) :
    receiver_socket(new tcp::socket(context)),
    sender_socket(new tcp::socket(context)) {};

session::session() {};

session::~session(){

    delete receiver_socket;
    delete sender_socket;
};




server::server() : 
    endpoint(tcp::endpoint(asio::ip::tcp::v4(), NET::DEFAULT_PORT)),
    acceptor(context),
    session_count(0)
{

    try
    {
        acceptor.open(endpoint.protocol());
        acceptor.bind(endpoint);
        acceptor.listen();

        std::cout << "*****************************\n";
        std::cout << "*Acceptor Binded to Endpoint*\n";
        std::cout << "*****************************\n";

    }


    catch (boost::system::system_error &syserr)
    {
        std::cerr << "error at acceptor binding: " << syserr.what() << '\n';
        exit(1);
    }

}




void server::start()
{   
    while(session_count < std::thread::hardware_concurrency())
    {
        
        session new_session;

        get_connection(new_session);

        m_sessions.push_back(std::move(new_session));


        std::thread transfer_thread([this](){
            begin_transfer(m_sessions.back());

        }); 
        
        transfer_thread.join();

        session_count++;

    }   
}




conn_type server::get_connection(session& session_)
{

    tcp::socket* socket;


for(int times =0; times<2; times++) // temporary loop im gonna delete it later
{
    socket = new tcp::socket(context);

    std::cout << "Waiting for connection\n\n" << std::flush;
    acceptor.accept(*socket, ec);

    if(ec)
    {
        std::cerr << "Connection accept error\n";
        NET::print_error_and_exit(ec);
    }

    std::cout << "new connection made: " << socket->remote_endpoint() << std::endl;


    std::string stringbuffer;
    stringbuffer.resize(16);

    asio::read_until(*socket, asio::dynamic_string_buffer(stringbuffer), "\n\n", ec);

    if(ec)
    {
        std::cerr << "Client request reading error\n";
        NET::print_error_and_exit(ec);
    }

    std::erase(stringbuffer, '\0');


    std::stringstream buffstream(stringbuffer);

    //taking id 
    std::getline(buffstream, session_.id); 


    {
        std::string sock_type;
        std::getline(buffstream, sock_type);

        if(sock_type == "S")
        {
            session_.sender_socket = std::move(socket);
            std::getline(buffstream, session_.filename);
        }

        if(sock_type == "A")
        {
            session_.receiver_socket = std::move(socket);
        }
    }

    

}//temp looop


}




void server::begin_transfer(session& session_)
{

    std::string filename_ = session_.filename + "\n\n";
    asio::write(*session_.receiver_socket, asio::buffer(filename_), ec);


    char ack[3]; /* client allow */ 
    asio::read(*session_.receiver_socket, asio::buffer(ack, 3), ec);
    

    asio::write(*session_.sender_socket, asio::buffer("start\n\n"), ec);
    

    if(ec)
    {
        NET::print_error_and_exit(ec);
    }



    if(ec)
    {
        std::cerr << "Error when sending start order to sender client\n";
        NET::print_error_and_exit(ec);
    }

    
    std::vector<char> buffer(1024); // 1 KB buffer

    while(true)
    {

        std::size_t bytes_read = session_.sender_socket->read_some(asio::buffer(buffer), ec);

        if(ec == asio::error::eof)
        {
            break;
        }

        else if(ec)
        {
            NET::print_error_and_exit(ec);
        }

 
        asio::write(*session_.receiver_socket, asio::buffer(buffer.data(), bytes_read), ec);

        if(ec)
        {
            NET::print_error_and_exit(ec);
        }
    }

    std::cout << "File Transferred" << std::endl;

    close_connections(session_);

    exit(EXIT_SUCCESS);

}




void server::close_connections(session& sockets)
{
    std::cout << "Closing clonnection ID: " << sockets.id << std::endl;
    
    NET::close_connection(*sockets.receiver_socket);
    NET::close_connection(*sockets.sender_socket);

    sockets.~session();

}