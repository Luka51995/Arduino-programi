void setup() {
  pinMode (9,OUTPUT); //crvena:
  pinMode (10,OUTPUT);//zuta:
  pinMode (11,OUTPUT);//ZELENA:
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite (9,HIGH);
  delay (6000);
  digitalWrite (9,LOW);
  
  digitalWrite (10,HIGH);
  digitalWrite (9,HIGH);
  delay (2000);
  digitalWrite (10,LOW);
  digitalWrite (9,LOW);
  delay(200);
  digitalWrite (11,HIGH);
  delay (6000);
  digitalWrite (11,LOW);
  delay (500);
    digitalWrite (10,HIGH);
  delay (2000);
  digitalWrite (10,LOW);
  delay(200);
  
  
  


  // put your main code here, to run repeatedly:

}
