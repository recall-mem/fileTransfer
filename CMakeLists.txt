cmake_minimum_required(VERSION 3.22)
project(fileTransfer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.74.0 REQUIRED COMPONENTS System)

include_directories(${Boost_INCLUDE_DIRS} include/)

add_executable(traf src/Client_main.cpp src/parse_arguments.cpp src/client.cpp)
add_executable(TransferService src/Server_main.cpp  src/server.cpp)

target_link_libraries(traf Boost::system)
target_link_libraries(TransferService Boost::system)
