#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
//#include "SPI.h"
//#include "MFRC522.h"
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);
//#define PREKIDAC A1
void setup() { 
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  
}
void loop() {
 lcd.print("Arduino"); // Prints "Arduino" on the LCD 
  
  
 lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("LCD tutorial"); 
 delay(1000); 

 lcd.clear(); // Clears the display 

 lcd.blink(); 
 delay (4000);
 lcd.setCursor(7,1); 
 delay(1000); 
 lcd.noBlink(); 
 
 lcd.cursor();
 delay(4000);
 lcd.clear(); // Clears the LCD screen 
}

