
#include <ultrasonic.h>

#define Led1 =7
#define Led2 =8
#define TRIGGER_PIN =12
#define ECHO_PIN = 13

int x;

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

 

void setup() {
 Serial.begin(9600)
 pinMode(Led1, OUTPUT);
 pinMode(Led2, OUTPUT);
 
}

void loop(){
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert ( microsec, Ultrasonic::IN);
  Serial.print("MS:");
  Serial.print(microsec);
  Serial.print(", CM:");
  Serial.print(cmSec);
  Serial.print(", IN:");
  Serial.print(inMsec);
  if(cmMsec>=30)
  digitalWrite(Led2, HIGH);
  if(cmMsec<30){
  digitalWrite(Led2, LOW);
  digitalWrite(Led1, HIGH);

     do{
     long microsec = ultrasonic.timing ();
     cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
     inMsec = ultrasonic.convert ( microsec, Ultrasonic::IN);
      x=map(cmMsec, 30, 0, 0, 500);

     }while(cmMse<=30);
     digitalWrite(Led1, LOW);
  }
   
  
}

