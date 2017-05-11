int V_out = A0;
int V_in = 3;
int ledPinW = 7;
int ledPinB = 10;
int ledPinG = 11;
int dB = 0;
int reading2 = 0;

void setup ()
{
  pinMode (ledPinB, OUTPUT);
  pinMode (ledPinG, OUTPUT);
  pinMode (ledPinW, OUTPUT);
  Serial.begin (9600);
}

void loop ()
{
  reading2 = (analogRead(V_out));
  float voltage2 = reading2 * (5.0 / 1023.0);
  float dB = 40 * log(V_in / voltage2);
  //Serial.println(reading2);
  //Serial.println(voltage2);  
  Serial.println(dB);
  delay(100);
  
}

