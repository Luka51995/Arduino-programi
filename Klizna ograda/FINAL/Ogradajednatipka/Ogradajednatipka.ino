 const int ON = 8; //set up our button constants
const int gateOpen = 7;
const int gateClosed = 6;
const int IN1 = 10;
const int IN2 = 11;
const int ENA = 9;
const int statLED = 5;
unsigned long currentTime = 0;
boolean gateState = false; //false = closed true = open
void setup() {
  Serial.begin(9600);
  pinMode(ON, INPUT); //set up I/O
  pinMode(gateOpen, INPUT);
  pinMode(gateClosed, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  analogWrite(ENA, 0); //make sure H-Bridge is off
  pinMode(statLED, OUTPUT); //setup our status LED
}
void loop() {
  if (digitalRead(ON) == HIGH && gateState == false) { //check to see if the button is pressed and the gate is closed
    analogWrite(ENA, 80); //enable h-bridge
    digitalWrite(IN1, HIGH); //configure for CW rotation
    digitalWrite(IN2, LOW);
    while(1){ //run motor until switch is tripped
      if (digitalRead(gateOpen) == HIGH) { //check switch state
        gateState = true;
        analogWrite(ENA, 40);
        delay(3000);
        //digitalWrite(statLED, LOW); //turn off LED
        analogWrite(ENA, 0); //disable h-bridge
        digitalWrite(IN1, LOW); //reset h-bridge config
        break;
      }
      if (millis() > currentTime + 500) { //flash status LED once
        digitalWrite(statLED, HIGH);
        delay(500);
        currentTime = millis();
      }
      else {
        digitalWrite(statLED, LOW);
      }
    }
  }
  if (digitalRead(ON) == HIGH && gateState == true) { //check to see if the button is pressed and the gate is open
    analogWrite(ENA, 80);
    digitalWrite(IN1, LOW); //configure for CCW rotation
    digitalWrite(IN2, HIGH);
    while(1){
      if (digitalRead(gateClosed) == HIGH) {
        gateState = false;
        analogWrite(ENA, 40);
        delay(3000);
        //digitalWrite(statLED, LOW);
        analogWrite(ENA,0);
        digitalWrite(IN2, LOW);
        break;
      }
      if (millis() > currentTime + 500) { //flash status LED once
        digitalWrite(statLED, HIGH);
        delay(500);
        currentTime = millis();
      }
      else {
        digitalWrite(statLED, LOW);
      }
    }
  }
}
