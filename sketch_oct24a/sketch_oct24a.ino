entiometer ValuesArduino

/* Arduino Stepper Control with Potentiometer

Created by Yvan / https://Brainy-Bits.com
This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/

#include <AccelStepper.h> 
// Library created by Mike McCauley at http://www.airspayce.com/mikem/arduino/AccelStepper/

// AccelStepper Setup
AccelStepper stepper(1, 2, 3);  // 1 = Easy Driver interface
                                  // Nano Pin 2 connected to STEP pin of Easy Driver
                                  // Nano Pin 3 connected to DIR pin of Easy Driver

// Variables to store current, previous and move position
int val = 0;
int previous = 0;
int long newval = 0;    

void setup() {
  stepper.setMaxSpeed(4800);  // Set speed fast enough to follow pot rotation
  stepper.setAcceleration(4800);  //  High Acceleration to follow pot rotation  
}

void loop() {
  val = analogRead(A4);  //  Read Potentiometer current value
  if ((val > previous+6) || (val < previous-6)) {  // Check that a move of the pot is at least > or < than 6
    newval = map(val, 0, 1023, 0, 1600);  // Map value (1600 = 1 stepper shaft rotation)
    stepper.runToNewPosition(newval);  // Move stepper to new position
    previous = val;  // save current value into variable previous
  }
}
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
/* Arduino Stepper Control with Potentiometer
 
Created by Yvan / https://Brainy-Bits.com
This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!
 
*/
 
#include <AccelStepper.h> 
// Library created by Mike McCauley at http://www.airspayce.com/mikem/arduino/AccelStepper/
 
// AccelStepper Setup
AccelStepper stepper(1, 2, 3);  // 1 = Easy Driver interface
                                  // Nano Pin 2 connected to STEP pin of Easy Driver
                                  // Nano Pin 3 connected to DIR pin of Easy Driver
 
// Variables to store current, previous and move position
int val = 0;
int previous = 0;
int long newval = 0;    
 
void setup() {
  stepper.setMaxSpeed(4800);  // Set speed fast enough to follow pot rotation
  stepper.setAcceleration(4800);  //  High Acceleration to follow pot rotation  
}
 
void loop() {
  val = analogRead(A4);  //  Read Potentiometer current value
  if ((val > previous+6) || (val < previous-6)) {  // Check that a move of the pot is at least > or < than 6
    newval = map(val, 0, 1023, 0, 1600);  // Map value (1600 = 1 stepper shaft rotation)
    stepper.runToNewPosition(newval);  // Move stepper to new position
    previous = val;  // save current value into variable previous
  }
