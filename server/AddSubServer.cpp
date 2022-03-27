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

    try {
        s->send(hdl, msg->get_payload(), msg->get_opcode());
    } catch (websocketpp::exception const & e) {
        std::cout << "Echo failed because: "
                  << "(" << e.what() << ")" << std::endl;
    }
}
