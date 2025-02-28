#include "net_common.h"
#include "parse_arguments.h"
#include <filesystem> // for sending directories
#include <fstream>
#include <getopt.h>

using namespace boost;
namespace fs = std::filesystem;
using tcp = asio::ip::tcp;
ArgumentParser::ArgumentParser(int argc_, char *args_[])
{
    Parse_args(argc_, args_);
    sendflg = false;
    acceptflg = false;
}

fs::path ArgumentParser::get_filepath() const { return filepath; }
std::string ArgumentParser::get_address() const { return address; }
std::string ArgumentParser::get_port() const { return port; }
std::string ArgumentParser::get_id() const { return id; }
bool ArgumentParser::is_send_flag() const { return sendflg; }
bool ArgumentParser::is_accept_flag() const { return acceptflg; }

void ArgumentParser::Parse_args(int argc, char *args[])
{
    const char *the_options = "e:i:p::f::sa";
    static struct option long_options[] = {
        {"send", no_argument, nullptr, 's'},
        {"accept", no_argument, nullptr, 'a'},
        {"id", required_argument, nullptr, 'i'},
        {"port", optional_argument, nullptr, 'p'},
        {"file", optional_argument, nullptr, 'f'},
        {"address", required_argument, nullptr, 'e'},
        {nullptr, 0, nullptr, 0}};

    int option;
    while ((option = getopt_long(argc, args, the_options, long_options, nullptr)) != -1)
    {
        switch (option)
        {
        case 'f':
            filepath = fs::path(optarg);
            break;

        case 'a':
            //acceptflg = true;
            break;
        case 's':
            //sendflg = true;
            break;

        case 'i':
            id = optarg;
            std::cout << "id: " << optarg << std::endl;
            break;
        case 'p':
            port = optarg;
            std::cout << "port: " << optarg << std::endl;
            break;
        case 'e':
            address = optarg;
            std::cout << "address: " << optarg << std::endl;
            break;
        default:
            std::cout << "wrong argument" << std::endl;
            break;
        };
    }

    if(filepath.empty() && (sendflg == true)){
        std::cerr << "Warning, FilePath is not provided\n"; exit(EXIT_FAILURE);
    } 

    if(address.empty()){
        std::cout << "Warning, server ip address is not provided\n";
        std::cout << "Default ip address will be used this time" << std::endl;
        address = NET::SERVER_IP;
    }

    if(port.empty()){
        std::cout << "Warning, server port is not provided\n";
        std::cout << "Default port will be used this time" << std::endl;
        port = std::to_string(NET::DEFAULT_PORT);
    }
}