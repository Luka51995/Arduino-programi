int buttonPin = 2;
boolean buttonState = LOW;
int motorPin = 10;
int motorEnabled = 0;
boolean previousButtonState = LOW;


void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if(previousButtonState != buttonState && buttonState == HIGH){
    motorEnabled = !motorEnabled;
    }
  if(motorEnabled == 1){
    digitalWrite (motorPin,HIGH);
    }
  else{
    digitalWrite (motorPin,LOW);
    }
  previousButtonState = buttonState;
}


