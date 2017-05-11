
const int buttonPin = 2;

boolean buttonState = LOW;         // variable for reading the pushbutton status

void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(buttonPin, INPUT);
  
  
 
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    analogWrite(9,80);
    }    
    
    
     
      else {
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
   
  
  }
 }
