int xpin = 1;
int ypin = 0;
int left = 2;
int right = 3;
int top = 4;
int bottom = 5;

void setup() {
  pinMode (xpin, INPUT);
  pinMode (ypin, INPUT);
  pinMode (left, OUTPUT);
  pinMode (right, OUTPUT);
  pinMode (top, OUTPUT);
  pinMode (bottom, OUTPUT);
  Serial.begin(9600);
  
  
  // put your setup code here, to run once:

}

void loop() {
  int xval;
  int yval;
  xval = analogRead(xpin);
  yval = analogRead (ypin);

  if (xval>1000){
    digitalWrite(right, HIGH);
  }
  else{
    digitalWrite(right, LOW);
  }
  if (xval<50){
    digitalWrite(left, HIGH);
  }
  else{
    digitalWrite(left, LOW);
  }
  if (yval>1000){
    digitalWrite(top, HIGH);
  }
  else{
    digitalWrite(top, LOW);
  }
  if (yval<50){
    digitalWrite(bottom, HIGH);
  }
  else{
    digitalWrite(bottom, LOW);
  }
  
  
  // put your main code here, to run repeatedly:

}
