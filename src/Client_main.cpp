#include <iostream>
#include <client.h>
#include <parse_arguments.h>

void print_usage() {
    std::cout << "Usage: ./program [OPTIONS]\n"
              << "Options:\n"
              << "  -f, --file <path>       Specify the file path to send or receive\n"
              << "  -s, --send              Enable send mode (required for sending a file)\n"
              << "  -a, --accept            Enable accept mode (required for receiving a file)\n"
              << "  -i, --id <identifier>   Provide an identifier for the transfer\n"
              << "  -e <address>            *Specify the IP address of the remote host\n"
              << "  -p <port>               *Specify the Port of the remote host\n"
              << "* = If no arguments provided for these options default values will be used\n"
              << "\n"
              << "Examples:\n"
              << "  ./program -f myfile.txt -s -e 192.168.1.10   # Send 'myfile.txt' to 192.168.1.10\n"
              << "  ./program -f received.txt -a                 # Accept incoming file as 'received.txt'\n"
              << "  ./program -f data.bin -s -i session123 -e 10.0.0.5  # Send 'data.bin' with ID to 10.0.0.5\n"
              << "\n"
              << "Note:\n"
              << "  - Either -s (send) or -a (accept) must be specified.\n"
              << "  - -f (file) is required.\n";
              //<< "  - -e (address) is required for sending (-s).\n";
}


int main(int argc, char* argv[]){

    if(argc == 1)
    {
        print_usage();
        return 1;
    }

    std::cout << argv[1] << std::endl;

    bool acf = false, sef = false;
    ArgumentParser args(argc, argv);

    std::string mode(argv[1]);

    if(mode.find("-s") != std::string::npos){
        sef = true;
    }

    else if(mode.find("-a") != std::string::npos){
        acf = true;
    }

    Client client(args.get_id(), args.get_address());
    
    if(acf)
    {
        std::cout << "accepting operation\n\n" << std::flush;
        client.accept_file();    
    }
    else if(sef)
    {
        std::cout << "sending operation\n\n" << std::flush;
        client.send_file(args.get_filepath());
    }
    else {
        std::cerr << "wrong arg" << argv[1] << ' ' << sizeof(argv[1]) << std::endl;
    }

    return 0;
}