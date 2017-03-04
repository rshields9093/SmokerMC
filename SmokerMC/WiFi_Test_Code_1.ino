// EspDebug - Test sketch for ESP8266 module

// Use this sketch with wiring described at http://www.instructables.com/id/Cheap-Arduino-WiFi-Shield-With-ESP8266/?ALLSTEPS
// This sketch uses an emulated second serial connection via the SoftSerial library.
// The user opens the serial monitor and connects with the usual serial interface (COM 3 in my case)
// Commnands typed into the serial monitor are transferred to the ESP via the emulated serial connection on pins 6 & 7
// This sketch will also use the built in second serial connection of a Aruduino Mega if present. Otherwise it uses emulated serial.

// emulate Serial1 if not present
#ifndef HAVE_HWSERIAL1
  #include "SoftwareSerial.h"
  SoftwareSerial Serial1(6, 7); // RX, TX
#endif

void setup()
{
  Serial.begin(115200); // serial port used for debugging
  Serial1.begin(9600);  // your ESP's baud rate might be different
}
 
void loop()
{
  if(Serial1.available())  // check if the ESP is sending a message
  {
    while(Serial1.available())
    {
      int c = Serial1.read(); // read the next character
      Serial.write((char)c);  // writes data to the serial monitor
    }
  }
 
  if(Serial.available())
  {
    // wait to let all the input command in the serial buffer
    delay(10);

    // read the input command in a string
    String cmd = "";
    while(Serial.available())
    {
      cmd += (char)Serial.read();
    }

    // print the command and send it to the ESP
    Serial.println();
    Serial.print(">>>> ");
    Serial.println(cmd);

    // send the read character to the ESP
    Serial1.print(cmd);
  }
}