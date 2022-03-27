#ifndef ADD_SUB_SERVER_HPP
#define ADD_SUB_SERVER_HPP

// Not using Boost Asio
#define ASIO_STANDALONE

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include "CommonTypes.hpp"

class AddSubServer
{
    public:
        AddSubServer();
        static void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg);
        void run();
    
    private:
        server addSubEndpoint;
};

#endif