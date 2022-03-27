#include <iostream>

#include "AddSubServer.hpp"

using websocketpp::lib::bind;
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;

//****************************************************************
// Default Constructor
AddSubServer::AddSubServer()
{
    // Setup Logging Endpoints
    addSubEndpoint.set_error_channels(websocketpp::log::elevel::all);
    addSubEndpoint.set_access_channels(websocketpp::log::alevel::all ^ websocketpp::log::alevel::frame_payload);
 
    // Initialize Asio
    addSubEndpoint.init_asio();

    // Setup the handler
    void (*on_message_ptr)(server* s, websocketpp::connection_hdl hdl, message_ptr msg) = &(this->on_message);
    server* addSubEndpoint_ptr = &addSubEndpoint;
    addSubEndpoint.set_message_handler(bind(&AddSubServer::on_message, &addSubEndpoint, ::_1, ::_2));
}


//****************************************************************
// run
//      - Start listening for requests to the server
void AddSubServer::run()
{
    addSubEndpoint.set_reuse_addr(true);
    addSubEndpoint.listen(9002);
    addSubEndpoint.start_accept();
    addSubEndpoint.run();
}


//****************************************************************
// on_message
//      - Handle incoming messages
void AddSubServer::on_message(server* s, websocketpp::connection_hdl hdl, message_ptr msg)
{
    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;

    // check for a special command to instruct the server to stop listening so
    // it can be cleanly exited.
    if (msg->get_payload() == "stop-listening") {
        s->stop_listening();
        return;
    }
    std::string jsonString = msg->get_payload();
    std::cout << "Got payload from client: " << jsonString << std::endl;

    std::string response = AddSubServer::processJsonReqStr(jsonString);
    std::cout << "Responding with: " << response << std::endl;

    try {
        s->send(hdl, response, msg->get_opcode());
    } catch (websocketpp::exception const & e) {
        std::cout << "Exception thrown when responding to request: "
                  << "(" << e.what() << ")" << std::endl;
    }
}

std::string AddSubServer::processJsonReqStr(std::string request)
{
    json jsonRequest = json::parse(request);
    json response;

    std::string type = jsonRequest["type"];
    uint a = jsonRequest["payload"]["a"];
    uint b = jsonRequest["payload"]["b"];

    uint returnVal = 0;
    std::string returnType = "ERROR";

    if (type.compare("add") == 0) 
    {
        std::cout << "Adding " << a << " + " << b << std::endl;
        returnVal = a + b;
        returnType = "addition";
    }
    else if (type.compare("sub") == 0)
    {
        std::cout << "Subtracting " << a << " - " << b << std::endl;
        returnVal = a - b;
        returnType = "difference";
    }
    else
    {
        // Couldnt process this 'type' - default return type ERROR and payload 0 will be used
        std::cout << "Unknown type in request" << std::endl;
    }

    response["type"] = returnType;
    response["payload"] = returnVal;

    return response.dump();
}
