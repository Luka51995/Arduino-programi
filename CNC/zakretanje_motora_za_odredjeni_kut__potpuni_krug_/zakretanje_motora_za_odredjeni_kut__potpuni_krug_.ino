#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define EN  6

char user_input;
int x;
int y;
//int state;

void setup() {
  // put your setup code here, to run once:
 pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(EN, OUTPUT);
  resetEDPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Zapocni kontrolu motora");
  Serial.println();
  //Print function list for user selection
  Serial.println("Unesi broj za odredjeni stupanj:");
  Serial.println("1. Okretanje za 180 stupnjeva (2 puta)");
  Serial.println("2. Okretanje za 90 stupnjeva (4 puta)");
  Serial.println("3. Okretanje za 45 stupnjeva (8 puta)");
  Serial.println("4. Okretanje za 60 stupnjeva (6 puta)");
  Serial.println("5. Okretanje za 360 stupnjeva");
  //Serial.println("6. Okretanje za 30 stupnjeva"); // ukloniti --> // ako želiš da piše: "5. Okretanje za 30 stupnjeva"
   
  Serial.println();
}

//Main loop
void loop() {
  while(Serial.available()){
      user_input = Serial.read(); //Read user input and trigger appropriate function
      digitalWrite(EN, LOW); //Pull enable pin low to allow motor control
      if (user_input =='1')
      {
         Stoosamdeset();
      }
      else if(user_input =='2')
      {
        Devedeset();
      }
      else if(user_input =='3')
      {
        Cetrdesetpet();
      }
      else if(user_input =='4')
      {
        Sezdeset();
      }
      //else if(user_input =='6') //ukloniti --> // ako želiš omogućiti rotaciju za 30 stupnjeva
      //{
        //Trideset();
      //}
      else if(user_input =='5')
      {
        Tristosezdeset();
      }
      else
      {
        Serial.println("Krivi unos");
      }
      resetEDPins();
      }
}

//Resetiraj Easy Driver pinove na default 

void resetEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(EN, HIGH);
}

//Okretanje za 360 stupnjeva
void Tristosezdeset()
{
  Serial.println("Okretanje za 360 stupnjeva");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x=1; x<200;  x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);
   
  }
  Serial.println("Enter new option");
  Serial.println();
}


//Okretanje za 180 stupnjeva (2 puta)

void Stoosamdeset()
{
  Serial.println("Okretanje za 180 stupnjeva");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x=1; x<100; x++)  // Prvi okret za 180 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay (3000); //unesi trajanje obrade (u milisekundama)

    for(x=1; x<100; x++)  // Drugi okret za 180 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }
    
  Serial.println("Enter new option");
  Serial.println();
}


//Okretanje za 90 stupnjeva (4 puta)

void Devedeset()
{
  Serial.println("Okretanje za 90 stupnjeva");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x=1; x<50; x++)  // Prvi zakret za 90 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay (3000); //unesi trajanje obrade (u milisekundama)

    for(x=1; x<50; x++)  // Drugi zakret za 90 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay (3000); //unesi trajanje obrade (u milisekundama)

     for(x=1; x<50; x++)  // Treći zakret za 90 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay (3000); //unesi trajanje obrade (u milisekundama)

    for(x=1; x<50; x++)  // Četvrti zakret za 90 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }
    
  Serial.println("Enter new option");
  Serial.println();
}


//Okretanje za 45 stupnjeva (8 puta)

void Cetrdesetpet()
{
  Serial.println("Okretanje za 45 stupnjeva");
  digitalWrite(dir, LOW); //Pull direction pin high to move in "reverse"
 for(x=1; x<25; x++)  // Prvi zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000);

 for(x=1; x<25; x++)  // Drugi zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000);

 for(x=1; x<25; x++)  // Treći zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000);   

 for(x=1; x<25; x++)  // Četvrti zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000);   

for(x=1; x<25; x++)  // Peti zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000);  

for(x=1; x<25; x++)  // Šesti zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000); 

for(x=1; x<25; x++)  // Sedmi zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

    delay (3000);  

 for(x=1; x<25; x++)  // Osmi zakret za 45 stupnjeva
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1);  }

             
  Serial.println("Enter new option");
  Serial.println();
}


//Okretanje za 60 stupnjeva (6 puta)

void Sezdeset()
{
  Serial.println("Okretanje za 60 stupnjeva");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x=1; x<34; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay(3000);

    for(x=1; x<34; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay(3000);

    for(x=1; x<34; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay(3000);

    for(x=1; x<34; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay(3000);

    for(x=1; x<34; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }

    delay(3000);

    for(x=1; x<34; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward
    delay(1);
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(1); }
    
  Serial.println("Enter new option");
  Serial.println();
}


//Okretanje za 30 stupnjeva

//void Trideset() //ukloniti sve --> ako želiš omogućiti rotaciju za 30 stupnjeva
//{
  //Serial.println("Okretanje za 30 stupnjeva");
 // digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
//  for(x=1; x<17; x++)  //Loop the forward stepping enough times for motion to be visible
 // {
 //   digitalWrite(stp,HIGH); //Trigger one step forward
  //  delay(1);
  //  digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
  //  delay(1);
    
 // }
  //Serial.println("Enter new option");
 // Serial.println();
//}

  //Serial.println("Enter new option:");
 // Serial.println();

