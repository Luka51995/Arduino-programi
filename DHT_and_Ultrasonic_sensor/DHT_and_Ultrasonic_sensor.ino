#include "DHT.h" //Uvoz DHT library

// definiranje pinova
const int trigPin = 9;
const int echoPin = 10;
const int LED =7;
#define DHTPIN 2 

// definiranje varijabli
long duration;
int distance;


//definiranje vrste DHT senzora (ukloniti komentare // za onau vrstu koju se koristi)
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
pinMode(trigPin, OUTPUT); // Postavlja trigPin kao Output
pinMode(echoPin, INPUT);// Postavlja echoPin kao Input
pinMode(LED, OUTPUT); //Postavlja LED pin kao Output
Serial.begin(9600); // Započinje serial communication
Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {
  
 //Ultrasonic sensor 
// Brisanje trigPin
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
//Serial.print("Distance: ");
//Serial.print(distance);
if (distance >100)
{digitalWrite (LED,HIGH);}
  else{ digitalWrite (LED, LOW);}


//DHT senzor temperature i vlažnosti
   float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t"); //\t znači razmak između podataka, tj novi stupac
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print(" *C\t");
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println (" mm");
  }
}


