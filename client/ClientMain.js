const { userInfo } = require('os');
const { exit } = require('process');
const WebSocket = require('ws');

var AddSubRequest = require('./AddSubRequest');
var AddSubClient = require('./AddSubClient');
const { lstat } = require('fs');

// Setup websocket client
const url = 'ws://localhost:9002';

addRequest = new AddSubRequest('add', 10, 5);
addClient = new AddSubClient(url, addRequest);

subRequest = new AddSubRequest('sub', 10, 5);
subClient = new AddSubClient(url, subRequest);