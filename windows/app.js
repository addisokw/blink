var SerialPort = require("serialport").SerialPort;
var serialPort = new SerialPort("COM6", {
    baudrate: 9600}, false);

serialPort.open(function (error) {
    if ( error ) {
        console.log('failed to open: '+error);
    } else {
        console.log('open');
    }
});

serialPort.on('data', function(data) {
    console.log(data.toString());
});

