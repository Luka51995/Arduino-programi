// definiranje pinova
const int trigPin = 9;
const int echoPin = 10;
const int LED =7;

// definiranje varijabli
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Postavlja trigPin kao Output
pinMode(echoPin, INPUT);// Postavlja echoPin kao Input
pinMode(LED, OUTPUT); //Postavlja LED pin kao Output
Serial.begin(9600); // Započinje serial communication
}

void loop() {
// Briše trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Postavlja trigPin u HIGH stanje 10 mikrosekundi
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Čita echoPin, vraća vrijeme putovanja zvučnog vala u mikrosekundama
duration = pulseIn(echoPin, HIGH);

// Izračunavanje udaljenosti
distance= duration*0.34/2; //daje udaljenost u mm

// Ispisuje udaljenost u Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" mm");
if (distance >100)
{digitalWrite (LED,HIGH);}
  else{ digitalWrite (LED, LOW);}
}


