

const int buttonForwardPin = 2;     // the number of the pushbutton pin
const int buttonRewersePin = 3;     // the number of the pushbutton pin

int buttonStateF = 0;
int buttonStateR = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(buttonRewersePin, INPUT);
  pinMode(buttonForwardPin, INPUT);
}

void loop() {
  buttonStateF = digitalRead(buttonForwardPin);
  buttonStateR = digitalRead(buttonRewersePin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonStateF == HIGH) {

    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    analogWrite(10, 250);
    buttonStateR = 0;
  }
  if (buttonStateR == HIGH) {

    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    analogWrite(10, 250);
    buttonStateF = 0;
  }
  buttonStateR = 0;
  buttonStateF = 0;
  // FORWARD

  delay(1000);

}
