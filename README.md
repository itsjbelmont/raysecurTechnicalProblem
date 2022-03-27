# RaySecur Addition/Subtraction Server (websocket++)
## Instructions From RaySecur
The purpose of this exercise is to demonstrate comfort implementing a simple communication protocol using C++ (specifically using the Websocket++ library). The task is to create a websocket server using the WebSocket++ library. The demo application should implement a simple messaging protocol across two endpoints; a server and a client.

* The server should be written in C++ and use the WebSocket++ library.
* It should implement a simple messaging protocol as described below.
* The client should be written in a scripting language (peferably node.js but python is acceptable). 
* The Messaging Protocol
* The server should implement a simple service enabling addition or subtraction of two numbers.

Communication between the server and its clients should be accomplished using messages.

The messages should be exchanged in JSON format. The format of the messages should be as follows: 

From the client, messages should have the following format:
```
{
  "type": [value as string],
  "payload": {
    "a": [value as number],
    "b": [value as number]
  }
} 
```
WHERE
1. The ~type~ property is a string which can take either of two values: "add" or "subtract".

2. The payload property should be an object with two scalar (numeric) properties: 'a' and 'b'.

The server should examine every client message and, depending on the type value send back to the client either the sum or the difference between 'a' and 'b'. 

The format of the server response message should be:
```
{
    "type": [value as string]
    "payload": [value as number] 
}
```
Where "type" permits either of two values: "sum" or "difference" and the payload is the computed result.


## Project Structure
* raysecurTechnicalProblem
    * server
        * contains the code for the http server
    * client
        * contains the code for the node.js client
    * asio-1.22.1
        * third party dependency. see next section for installation proceedure (not tracked by git)
    * websocketpp
        * third party dependency. see next section for installation proceedure (not tracked by git)
    * json
        * third party dependency. see next section for installation proceedure (not tracked by git)


## Installing Dependancies
Before running the code in this project's githup directory you must install the dependencies as follows

### websocket++
1. cd {raysecurTechnicalProblem}
2. git clone https://github.com/zaphoyd/websocketpp.git

### asio
1. Download tar.gz file at [this link](https://sourceforge.net/projects/asio/files/asio/1.22.1%20%28Stable%29/)
2. mv {tarfile} {raysecurTechnicalProblem}
3. tar -xzvf {tarfile}
4. rm -f {tarfile}

### json
1. cd {raysecurTechnicalProblem}
2. git clone https://github.com/nlohmann/json.git

### CHECK THE CONFIGURATION IN THE SERVER MAKEFILE
Check the following flags in the raysecurTechnicalProblem/server/makefile. If you have installed these files to separate directories than what I did in my configuration then you will need to update these local paths
* WEBSOCKETPP =
* ASIO = 
* JSON = 