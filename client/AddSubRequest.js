// Object to represent the JSON requests
function AddSubRequest(type, a, b) {
    this.type = type;
    this.payload = new Payload(a,b);

    function Payload(a, b) {
        this.a = a;
        this.b = b;
    }
}

module.exports = AddSubRequest;