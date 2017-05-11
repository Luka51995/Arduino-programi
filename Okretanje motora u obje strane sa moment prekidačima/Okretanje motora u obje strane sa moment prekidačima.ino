const int napred = 2;
const int nazad = 3;
int buttonStatenapred = 0;         // variable for reading the pushbutton status
int buttonStatenazad = 0; 
void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(napred, INPUT);
  pinMode(nazad, INPUT);
  
 
}

void loop() {
  // read the state of the pushbutton value:
  buttonStatenapred = digitalRead(napred);
  buttonStatenazad = digitalRead(nazad);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonStatenapred == HIGH) {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,60);
    buttonStatenazad = 0;
    delay(20000);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    }  
  if  (buttonStatenazad == HIGH){
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,60);
      buttonStatenapred = 0;
      delay(2000);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
  }
    buttonStatenapred = 0; 
    buttonStatenazad = 0;
 }
