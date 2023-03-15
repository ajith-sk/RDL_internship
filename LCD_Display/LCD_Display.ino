#include<LiquidCrystal.h>                        // Include the LCD library
//LiquidCrystal lcd(2,15,13,12,14,27); 
LiquidCrystal lcd(16,17,19,21,22,23); //Port P2 Mapping the pins with library
void setup()
{
Serial.begin(9600);                              //Baud Rate
lcd.begin(16,2);                                 //initializing 16X2 LCD display
}
void loop()
{
lcd.setCursor(0,0);                              //first line in display
lcd.print("SELVARAJ KALPANA");
Serial.print("SELVARAJ KALPANA");
delay(3000);
//lcd.clear();
lcd.setCursor(0,1);                              //second line in display
lcd.print("GAYATHRI AJITHSK");
Serial.print("GAYATHRI AJITHSK");
delay(3000);
lcd.clear();
}
