int xpin = 1;
int ypin = 0;
int left = 2;
int leftm = 3;
int center = 4;
int rightm = 5;
int right = 6;
int top = 7;
int topm = 8;
int bottomm = 9;
int bottom = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(left, OUTPUT);
  pinMode(leftm, OUTPUT);
  pinMode(center, OUTPUT);
  pinMode(rightm, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(top, OUTPUT);
  pinMode(topm, OUTPUT);
  pinMode(bottomm, OUTPUT);
  pinMode(bottom, OUTPUT);
  Serial.begin(9600);
  digitalWrite(center, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int xval;
  int yval;
  xval = analogRead(xpin);
  yval = analogRead(ypin);
  Serial.print(xval);
  Serial.print(" ");
  Serial.println(yval);
  
  if(yval>520) {
    digitalWrite(topm, HIGH);
  }
  else {
    digitalWrite(topm, LOW);
  }
  if(yval>1000) {
    digitalWrite(top, HIGH);
  }
  else {
    digitalWrite(top, LOW);
  }
  if(yval<510) {
    digitalWrite(bottomm, HIGH);
  }
  else {
    digitalWrite(bottomm, LOW);
  }
  if(yval < 50) {
    digitalWrite(bottom, HIGH);
  }
  else {
    digitalWrite(bottom, LOW);
  }
  if(xval>520) {
    digitalWrite(rightm, HIGH);
  }
  else {
    digitalWrite(rightm, LOW);
  }
  if(xval>1000) {
    digitalWrite(right, HIGH);
  }
  else {
    digitalWrite(right, LOW);
  }
  if(xval<510) {
    digitalWrite(leftm, HIGH);
  }
  else {
    digitalWrite(leftm, LOW);
  }
  if(xval < 50) {
    digitalWrite(left, HIGH);
  }
  else {
    digitalWrite(left, LOW);
  }
}
