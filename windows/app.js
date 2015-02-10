var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("COM3", {
    baudrate: 9600
});

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

/*
serialPort.close(function (error) {
    if ( error ) {
        console.log('failed to close: ' + error);
    } else {
        console.log('closed');
    }
});*/
