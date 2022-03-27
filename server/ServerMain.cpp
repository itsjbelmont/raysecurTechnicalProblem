#include <iostream>

// Not using Boost Asio
#define ASIO_STANDALONE

// websocketpp includes
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

// My Includes
#include "AddSubServer.hpp"
#include "CommonTypes.hpp"

int main() {
    std::cout << "STARTING SERVER MAIN" << std::endl;
    AddSubServer addSubServer = AddSubServer();
    addSubServer.run();
}