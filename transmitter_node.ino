// Transmitter Node

#include <SoftwareSerial.h>
#define tx 2        // blutooth tx pin
#define rx 3        // blutooth rx pin
#define echoPin 4   // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 5   //attach pin D3 Arduino to pin Trig of HC-SR04

SoftwareSerial configBt(rx, tx);    // RX, TX
long duration;                      // variable for the duration of sound wave travel
int distance;                       // variable for the distance measurement
int tres_dist = 100;
void setup() 
{
    pinMode(trigPin, OUTPUT);   // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT);    // Sets the echoPin as an INPUT
    pinMode(tx, OUTPUT);        
    pinMode(rx, INPUT);
    Serial.begin(9600);
    configBt.begin(9600);
}

void loop() 
{
    digitalWrite(trigPin, LOW);         // Clears the trigPin condition
    delay(100);
    digitalWrite(trigPin, HIGH);        // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    delay(100);
    digitalWrite(trigPin, LOW);         // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);  // Calculating the distance
    distance = duration * 0.034 / 2;    // Speed of sound wave divided by 2 (go and back)
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm")
    
    if(distance < tres_dist)
    {
        Serial.println("Treshold height reached, transmitting alert ....")
        configBt.write(100);            // Transmit 100
    }
}