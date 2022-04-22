#include <NewPing.h>

#define TRIGGER_PIN  12  
#define ECHO_PIN     11 
#define MAX_DISTANCE 200 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
//These are the Pin Numbers.
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;

void setup() {
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT); 
}

void loop() {
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
  
  int duration, distance;
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = sonar.ping_cm();
    if (distance <= 20 && distance > 0) {
      digitalWrite(buzzPin, HIGH);
    }
    else if (distance <=30 && distance >= 21){
      digitalWrite(buzzPin,HIGH);
      delay(40);
      digitalWrite(buzzPin, LOW);
    }
    else if (distance <=40 && distance >= 31){
      digitalWrite(buzzPin,HIGH);
      delay(80);
      digitalWrite(buzzPin, LOW);
    }
    else if (distance <=60 && distance >= 41){
      digitalWrite(buzzPin,HIGH);
      delay(200);
      digitalWrite(buzzPin, LOW);
    }
    else
    {
      digitalWrite(buzzPin, LOW);
    }
}
