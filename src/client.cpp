#include "net_common.h"
#include "client.h"
#include "parse_arguments.h"
#include <fstream>
#include <filesystem>

using namespace boost;
namespace fs = std::filesystem;
using tcp = asio::ip::tcp;

    Client::Client(const std::string id_, const std::string address_) : socket(context)
    {   
        id = (id_);
        address = address_;
        endpoint = tcp::endpoint(asio::ip::make_address_v4(address), NET::DEFAULT_PORT);
    }

    void Client::send_file(const fs::path& FILEPATH) noexcept
    {

        // Im adding a new line character for use as delim for asio::read_until to seprate filename from meta data
        std::string   filename = FILEPATH.filename();
        std::ifstream file(FILEPATH, std::ios::binary);
        filename += "\n\n";

        char rawBuffer[4096];
        int  bytes;



        if (!file.is_open())
        {

            std::cout << "File not open" << std::endl;

            if (!fs::exists(FILEPATH))

                std::cout << FILEPATH << " not exists" << std::endl;

            exit(EXIT_FAILURE);
        }



        file.seekg(0, std::ios::end);
        size_t file_size = file.tellg();
        file.seekg(0, std::ios::beg);
        size_t totalbytes = 0;


        make_connection("S\n");


        if(ec)
        {
            NET::print_error_and_exit(ec);
        }
        


        try
        {

            asio::write(socket, asio::buffer(filename.data(), filename.size()), ec);

            
            std::string lock;
            lock.reserve(16);
            asio::read_until(socket, asio::dynamic_string_buffer(lock), "\n\n", ec);

            if(ec)
            {
                std::cerr << "error at receiving start command\n";
                NET::print_error_and_exit(ec);
            }
            

            if(lock.find("start") == std::string::npos)
            {
                std::cerr << "unknown response from server\n";
                NET::close_connection(socket);

                exit(EXIT_FAILURE);
            }


            std::cout << "Transfer started\n" << std::flush;

            while (file.read(rawBuffer, sizeof(rawBuffer)) || (bytes = file.gcount()) > 0)
            {
                std::cout << bytes << " bytes sended\r";

                asio::write(socket, asio::buffer(rawBuffer, bytes));
            }

            std::cout << std::endl;
        
        }

        catch (boost::system::system_error &erc)
        {

            std::cout << "Error at sending file\n";
            std::cout << erc.what() << std::endl;

            exit(EXIT_FAILURE);

        }

        std::cout << "Operation finished succesfuly" << std::endl;
      
      

        // closing the socket
        NET::close_connection(socket);
        file.close();

        exit(EXIT_SUCCESS);


    } // send_file



    void Client::accept_file(std::string FILEPATH) noexcept
    {


        std::cout << "Starting to accepting operation" << std::endl;
        std::ofstream file;
        std::string   filename;


        make_connection("A\n\n");

        filename.resize(32);
        asio::read_until(socket, asio::dynamic_buffer(filename), "\n\n", ec);

        if(ec)
        {
            NET::print_error_and_exit(ec);
        }

        std::erase(filename, '\n');
        std::erase(filename, '\0');
        std::erase(filename, ' ');



        file.open(filename, std::ios::binary);

        if (!file.is_open())
        {
            std::cout << "file not open" << std::endl;

            NET::close_connection(socket);
            exit(EXIT_FAILURE);
        }



        size_t bytes_read = 0;
        char   rawBuffer[2048];

        asio::write(socket, asio::buffer("OK"));

        while(true)
        {

            bytes_read = socket.read_some(asio::buffer(rawBuffer), ec);
            
            if (ec == asio::error::eof)
            {
                std::cout << "File received succesfully" << std::endl;
                break;
            }
            
            if (ec)
            {
                std::cerr << "Error during receiving file: " << ec.message() << "\n";
                NET::close_connection(socket);

                exit(EXIT_FAILURE);
            }

            file.write(rawBuffer, bytes_read);
        
        }



        file.close();
        NET::close_connection(socket);

        exit(EXIT_SUCCESS);


    }

    void Client::make_connection(std::string connection_type)
    {
        std::string fullmessage(
            id + '\n' + connection_type
        );


        socket.connect(endpoint, ec);

        if(ec)
        {
            std::cerr << "Connecting error\n";
            NET::print_error_and_exit(ec);
        }



        asio::write(socket, asio::buffer(fullmessage), ec);

        if(ec)
        {
            std::cerr << "Error when sending fullmessage\n";
            NET::close_connection(socket);
            NET::print_error_and_exit(ec);
        }

    }
