// Slave Receiver Node

#define valvePin 13                        // Valve Pin

int data = -1;
bool valveOn = false;								       // Valve off by default

void setup()
{
    Serial.begin(9600);
    pinMode(valvePin, OUTPUT);
  	digitalWrite(valvePin, LOW);           // Valve off by default
}

void loop()
{
    if(Serial.available() > 0 )                             // Check receiver buffer
    {
        data = Serial.read();                 		          // Read receiver buffer
        Serial.print("Data received: ");
        Serial.println(data);
        
        if(data == 103 & !valveOn){
            Serial.println("Turning on valve ........");
          	digitalWrite(valvePin, HIGH);                   // Turn on valve
          	valveOn = true;
          	Serial.println("Valve turned on ........");
        }
      
        if(data == 115 & valveOn){
            Serial.println("Turning off valve ........");
          	digitalWrite(valvePin, LOW);					          // Turn off valve
          	valveOn = false;
          	Serial.println("Valve turned off ........");
        }
    }
}