const WebSocket = require('ws');

// The object of our request - to be converted to JSON
const AddSubRequest = require('./AddSubRequest');

function AddSubClient(url, objToSend) {
    // Member Variables
    this.url = url;
    this.objToSend = objToSend
    this.ws = new WebSocket(this.url);

    // Setup the event handlers
    this.ws.onopen = () => this.onAddSubClientConnect();
    this.ws.onmessage = (event) => this.onAddSubClientMessage(event);
    this.ws.onclose = () => this.onAddSubClientClose();
}

AddSubClient.prototype.onAddSubClientConnect = function () {
    console.log("Connected to websocket: " + this.url)
    this.sendObjAsJson(this.objToSend);
}

AddSubClient.prototype.onAddSubClientMessage = function (event) {
    console.log("Recieved message from websocket: " + event.data);
    this.ws.close();
}

AddSubClient.prototype.onAddSubClientClose = function () {
    console.log("Connection closed to websocket: " + this.url);
}

AddSubClient.prototype.sendObjAsJson = function (obj) {
    jsonObj = JSON.stringify(obj);
    console.log("Sending message from websocket: " + jsonObj);
    this.ws.send(jsonObj);
}

module.exports = AddSubClient;