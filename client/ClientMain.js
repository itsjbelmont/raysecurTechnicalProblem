const { exit } = require('process');
const WebSocket = require('ws');
const AddSubRequest = require('./AddSubRequest');

// Setup websocket client
const url = 'ws://localhost:9002';
const connection = new WebSocket(url);

connected = false;

connection.onopen = () => {
    console.log("Connected to WebSocket at: " + url)
    addRequest = new AddSubRequest('add', 10, 5);
    subRequest = new AddSubRequest('sub', 20, 2);

    console.log("\nSending payload: " + JSON.stringify(addRequest));
    connection.send(JSON.stringify(addRequest));

    console.log("\nSending payload: " + JSON.stringify(subRequest));
    connection.send(JSON.stringify(subRequest));
}

connection.onerror = (error) => {
    console.log('WebSocket error: ' + error);
}

connection.onclose = () => {
    console.log('WebSocket closed.');
}

connection.onmessage = (e) => {
    console.log("\nRecieved message from WebSocket:");
    console.log(e.data);
}

