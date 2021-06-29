// Master Transmitter Node

#define echoPin 12					// Echo Pin
#define trigPin 11					// Trigger Pin

long duration;                      // variable for the duration of sound wave travel
int distance;                       // variable for the distance measurement
int tres_dist = 4;					// max height to turn off valve
int refill_dist = tres_dist + 4;	// min height to turn on valve
bool valveOn = false;

void setup() {
	pinMode(trigPin, OUTPUT);       // Sets the trigPin as an OUTPUT
  	pinMode(echoPin, INPUT);        // Sets the echoPin as an INPUT
  	Serial.begin(9600); 			// Default communication rate of the Bluetooth module
}

int getDistance(){
    digitalWrite(trigPin, LOW);         	// Clears the trigPin condition
    delay(100);
    digitalWrite(trigPin, HIGH);        	// Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    delay(100);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);      // Reads the echoPin, returns the sound wave travel time in microseconds
    distance = (int)duration * 0.034 / 2;   // Calculating the distance, speed of sound wave divided by 2 (go and back)
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
}

void loop() {
  	int dist = getDistance();
	if(dist <= tres_dist & valveOn)
    {
        Serial.println("Treshold max height reached, transmitting alert ....");
      	Serial.write('g');                  // Transmit 100
      	valveOn = false;
    }

    if(dist > refill_dist & !valveOn){
        Serial.println("Treshold min height reached, transmitting alert ....");
        Serial.write('s');				// Transmit 100
        valveOn = true;
    }

 	delay(2000);
}