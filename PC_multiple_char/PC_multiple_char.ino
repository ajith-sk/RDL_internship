#include<LiquidCrystal.h>                        // Include the LCD library
// LiquidCrystal lcd(2,15,13,12,14,27); 
LiquidCrystal lcd(16,17,19,21,22,23); //Port P2 Mapping the pins with library


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0); 
  Serial.println("Enter your name.");
  lcd.println("Enter your name.");
}

char rx_byte = 0;
String rx_str = "";

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    
    if (rx_byte != '\n') {
      // a character of the string was received
      rx_str += rx_byte;
    }
    else {
      // end of string
      
      lcd.setCursor(0,1);  
      Serial.print("Welcome ");
      lcd.print("Welcome ");
      
      lcd.setCursor(8,1);
      Serial.println(rx_str);
      lcd.println(rx_str);
      
      rx_str = "";                // clear the string for reuse
      lcd.setCursor(0,1);
      Serial.print(rx_str);
      lcd.print(rx_str);
      
      lcd.setCursor(0,0);
      Serial.println("Enter your name.");
      lcd.println("Enter your name.");
    }
  } // end: if (Serial.available() > 0)
}
