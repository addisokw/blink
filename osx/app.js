var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("/dev/cu.usbmodem141111", {
  baudrate: 9600
});
var applescript = require('applescript');
var script = 'ActiveShot.scpt';

serialPort.open(function (error) {
  if ( error ) {
    console.log('failed to open: '+error);
  } else {
    console.log('open');
 }
});
    
serialPort.on('data', function(data) {
  console.log(data.toString());
  if(data.toString() == 1){
     applescript.execFile(script, function(err) {
       if (err) {
         // Something went wrong! 
        } else {
          console.log('success');
        }
     });
   }
})

