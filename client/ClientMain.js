const { userInfo } = require('os');
const { exit } = require('process');
const WebSocket = require('ws');

var AddSubRequest = require('./AddSubRequest');
var AddSubClient = require('./AddSubClient');
const { lstat } = require('fs');
const { syncBuiltinESMExports } = require('module');

// Function to add a bit of delay between requests
function sleep(ms) {
    return new Promise((resolve) => {
        setTimeout(resolve, ms);
    });
}

// Function to send a bunch of requests to the websocket
async function connectAndSendRequests() {
    // Setup websocket client
    const url = 'ws://localhost:9002';

    requests = [
        new AddSubRequest('add', 10, 5), 
        new AddSubRequest('add', -5, -10),
        new AddSubRequest('add', 100, 11),
        new AddSubRequest('add', 1, 0),
        new AddSubRequest('sub', -1, 5), 
        new AddSubRequest('sub', -8, -2), 
        new AddSubRequest('sub', 40, 100), 
        new AddSubRequest('sub', 100, 87), 
    ];

    for (i = 0; i < requests.length; i++) {
        req = requests[i];
        addClient = new AddSubClient(url, req);
        await sleep(500);
    }
}

connectAndSendRequests();