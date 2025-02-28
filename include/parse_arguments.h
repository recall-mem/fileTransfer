#ifndef PARSE_ARGUMENTS_H
#define PARSE_ARGUMENTS_H

#include "net_common.h"
#include <filesystem> // for sending directories

using namespace boost;
namespace fs = std::filesystem;
using tcp = asio::ip::tcp;


struct ArgumentParser
{
    ArgumentParser(int argc_, char *args_[]);

    
    fs::path get_filepath() const;
    std::string get_address() const; 
    std::string get_port() const;
    std::string get_id() const;
    bool is_send_flag() const;
    bool is_accept_flag() const;


private:
    void Parse_args(int argc, char* args[]);

    fs::path filepath;
    std::string address;
    std::string port;
    std::string id;

    bool sendflg, acceptflg;

};

#endif