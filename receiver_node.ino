// Receiver:
 
#include <SoftwareSerial.h>

#define tx 2
#define rx 3
SoftwareSerial configBt(rx, tx); //RX, TX

String data = 0;

void setup()
{
    Serial.begin(9600);
    configBt.begin(9600);
    pinMode(tx, OUTPUT);
    pinMode(rx, INPUT);
}

void loop()
{
    if(configBt.available() > 0 )		// Check receiver buffer
    {
        data = configBt.readString()		// Read receiver buffer
        Serial.print("Data received: ");
        Serial.print(data);
        
        if(data == "100"){
            // Do something with Solenoid valve
        }
    }
}