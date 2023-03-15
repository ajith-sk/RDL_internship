const int input = 25; // This is where the input is fed.
int pulse = 0; // Variable for saving pulses count.
int var = 0;
#include<LiquidCrystal.h> // Include the LCD library
LiquidCrystal lcd(2,15,13,12,14,27); 
void setup(){
pinMode(input, INPUT);

Serial.begin(9600);
lcd.begin(16,2); 
Serial.println(F("No pulses yet...")); // Message to send initially (no pulses detected yet).
}

void loop(){
if(digitalRead(input) > var)
{
var = 1;
pulse++;

Serial.print(pulse);
Serial.print(F(" pulse"));

// Put an "s" if the amount of pulses is greater than 1.
if(pulse > 1) {Serial.print(F("s"));}

Serial.println(F(" detected."));
lcd.setCursor(0,0); //first line in display
lcd.print("pulse detected:");
lcd.setCursor(0,1);
lcd.print(pulse);
delay(100);
}

if(digitalRead(input) == 0) {var = 0;}

delay(1); // Delay for stability.
}
