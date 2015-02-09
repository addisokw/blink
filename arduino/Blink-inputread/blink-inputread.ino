#include "Wire.h"

byte input=0;
byte last=0;
int hotkeyArray[] = { 
  225, 226, 227, 228, 229, 230, 231, 232 };


void setup()
{
  Serial.begin(9600);
  Wire.begin(); // wake up I2C bus
  
  //set bank A to outputs
//  Wire.beginTransmission(0x20);
//  Wire.write(0x00); // IODIRA register
//  Wire.write(0x00); // set all of bank A to outputs
//  Wire.endTransmission();
  
  Keyboard.begin(); //initiate Keyboard control
}

int convertDecimal (byte binary)
  {
    int dec = 0;
      if(binary == B11111110)
    {
        dec = 0;
        return dec;
    }  
   
      if(binary == B11111101)
    {
        dec = 1;
        return dec;
    }  
      if(binary == B11111011)
    {
        dec = 2;
        return dec;
    }  
    if(binary == B11110111)
    {
        dec = 3;
        return dec;
    }  
    if(binary == B11101111)
    {
        dec = 4;
        return dec;
    }  
    if(binary == B11011111)
    {
        dec = 5;
        return dec;
    }  
    if(binary == B10111111)
    {
        dec = 6;
        return dec;
    }  
    if(binary == B01111111)
    {
        dec = 7;
        return dec;
    }  
 
  }

void loop()
{
  Wire.beginTransmission(0x24);
  Wire.write(0x12); // set MCP23017 memory pointer to GPIOB address
  Wire.endTransmission();
  Wire.requestFrom(0x24, 1); // request one byte of data from MCP20317
  input=Wire.read(); // store the incoming byte into "input"
  if (input == last){ // do not repeat previous input
    input = 0;
  }
  if (input>0  && input != 255) // if a button was pressed
  {
    //Serial.println(input, BIN); // display the contents of the GPIOB register in binary
    delay(250); // for debounce
    int count = convertDecimal(input);
    //Serial.println(count);
    int key = hotkeyArray[count];
    // Serial.println(key);
    // Keyboard.press(key);
    // Keyboard.releaseAll();
    Serial.print(count+1);
    last = input;
    
  }
}
