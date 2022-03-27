#ifndef ADD_SUB_SERVER_HPP
#define ADD_SUB_SERVER_HPP

// Not using Boost Asio
#define ASIO_STANDALONE

#include <string>

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <nlohmann/json.hpp>

#include "CommonTypes.hpp"

using json = nlohmann::json;

class AddSubServer
{
    public:
        AddSubServer();
        static void on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg);
        static std::string processJsonReqStr(std::string request);
        void run();
    
    private:
        server addSubEndpoint;
};

#endif