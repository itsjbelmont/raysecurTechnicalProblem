const WebSocket = require('ws');

// The object of our request - to be converted to JSON
const AddSubRequest = require('./AddSubRequest');

function AddSubClient(url, objToSend) {
    // Member Variables
    this.url = url;
    this.objToSend = objToSend
    try {
        this.ws = new WebSocket(this.url);
    } catch (e) {
        console.log("Exception thrown when trying to create a new WebSocket object with url: " + this.url)
    }

    // Setup the event handlers
    this.ws.onopen = () => this.onAddSubClientConnect();
    this.ws.onmessage = (event) => this.onAddSubClientMessage(event);
}

AddSubClient.prototype.onAddSubClientConnect = function () {
    // When we connect to the websocket send our object
    this.sendObjAsJson(this.objToSend);
}

AddSubClient.prototype.onAddSubClientMessage = function (event) {
    // Log the message and exit the connection
    console.log("Recieved message from websocket: " + event.data + "\n");
    this.ws.close();
}

AddSubClient.prototype.sendObjAsJson = function (obj) {
    jsonObj = JSON.stringify(obj);
    console.log("Sending message from websocket: " + jsonObj);
    this.ws.send(jsonObj);
}

module.exports = AddSubClient;