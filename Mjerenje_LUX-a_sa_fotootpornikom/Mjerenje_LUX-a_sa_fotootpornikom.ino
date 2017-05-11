int whiteLedPin = 2;
int greenLedPin = 3;
int blueLedPin = 4;

int lightSensorPin = A0;
int analogValue= 0;


void setup() {
  
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

float analogValue = analogRead(lightSensorPin);
//Serial.println (analogValue);

float V0 = (5*analogValue/(analogValue+5,1))/1000;
float LUX = (2500/V0-500)/5.1;
Serial.print ("Napon ");
Serial.print (V0);
Serial.print (" [V]  \t");
Serial.print ("LUX ");
Serial.print (LUX);
Serial.println (" [lx]");
delay (1000);

}
  

  
 


