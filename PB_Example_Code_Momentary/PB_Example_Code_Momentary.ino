int buttonPin = 2;
boolean buttonState = LOW;
int motorPin = 10;



void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH){
    digitalWrite(motorPin,HIGH);
    }
  else{
    digitalWrite(motorPin,LOW);
    }
}


