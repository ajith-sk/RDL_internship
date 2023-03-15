#include "Wire.h"
#include<LiquidCrystal.h> // Include the LCD library 

//this only works in Non RDL kit.

//LiquidCrystal lcd(02,15,13,12,14,27);      //for port3 pins. (only in port 3 it works)
LiquidCrystal lcd(16,17,19,21,22,23);        //for port2 pins.
#define DS1307_I2C_ADDRESS 0x68
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val){
return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val){
return( (val/16*10) + (val%16) );
}
void setup(){
//String a="ami";
Wire.begin();
Serial.begin(9600);
delay(1000); 
lcd.begin(16,2); 
 // set the initial time here:
setDS1307time(00,15,11,2,20,2,23); // DS1307 seconds, minutes, hours, day, date, month, 

 //delay(1000); 
}
void setDS1307time(byte second, byte minute, byte hour, byte dayOfWeek, byte
dayOfMonth, byte month, byte year){
// sets time and date data to DS1307
Wire.beginTransmission(DS1307_I2C_ADDRESS);
Wire.write(0); // set next input to start at the seconds register
Wire.write(decToBcd(second)); // set seconds
Wire.write(decToBcd(minute)); // set minutes
Wire.write(decToBcd(hour)); // set hours
Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
Wire.write(decToBcd(month)); // set month
Wire.write(decToBcd(year)); // set year (0 to 99)
Wire.endTransmission();
}
void readDS1307time(byte *second, byte *minute, byte *hour,byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year)
{
Wire.beginTransmission(DS1307_I2C_ADDRESS);
Wire.write(0); // set DS1307 register pointer to 00h
Wire.endTransmission();
delay(100);
Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
// request seven bytes of data from DS1307 starting from register 00h
*second = bcdToDec(Wire.read() & 0x7f);
*minute = bcdToDec(Wire.read());
*hour = bcdToDec(Wire.read() & 0x3f);
*dayOfWeek = bcdToDec(Wire.read());
*dayOfMonth = bcdToDec(Wire.read());
*month = bcdToDec(Wire.read());
*year = bcdToDec(Wire.read());
 Wire.endTransmission();
}
void displayTime(){
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
// retrieve data from DS1307
//updated by amith
readDS1307time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
&year);
// send it to the serial monitor
Serial.print(hour, DEC);
lcd.setCursor(0,0);

lcd.print(hour,DEC);

// convert the byte variable to a decimal number when displayed
Serial.print(":");
if (minute<10){
 Serial.print("0");
}
Serial.print(minute, DEC);
lcd.setCursor(2,0);
lcd.print(":");
lcd.setCursor(3,0);

lcd.print(minute,DEC);

Serial.print(":");
if (second<10){
 Serial.print("0");
}
Serial.print(second, DEC);
Serial.print(" ");

lcd.setCursor(5,0);
lcd.print(":");
lcd.setCursor(6,0);

lcd.print(second,DEC);
lcd.setCursor(8,0);
lcd.print("|");
Serial.print(dayOfMonth, DEC);
lcd.setCursor(0,1);
lcd.print(dayOfMonth, DEC);
Serial.print("/");
Serial.print(month, DEC);
lcd.setCursor(2,1);
lcd.print("/");
lcd.setCursor(3,1);

lcd.print(month,DEC);
Serial.print("/");
Serial.print(year, DEC);
lcd.setCursor(5,1);
lcd.print("/");
lcd.setCursor(6,1);

lcd.print(year,DEC);
Serial.print(" Day of week: ");
switch(dayOfWeek){
case 1:
 Serial.println("Sunday");
 lcd.setCursor(9,0);
 lcd.print("Sunday");
 break;
case 2:
 Serial.println("Monday");
  lcd.setCursor(9,0);
 lcd.print("mon");
 break;
case 3:
 Serial.println("Tuesday");
  lcd.setCursor(9,0);
 lcd.print("tue");
 break;
case 4:
 Serial.println("Wednesday");
  lcd.setCursor(9,0);
 lcd.print("wed");
 break;
case 5:
 Serial.println("Thursday");
  lcd.setCursor(9,0);
 lcd.print("thu");
 break;
case 6:
 Serial.println("Friday");
  lcd.setCursor(9,0);
 lcd.print("fri");
 break;
case 7:
 Serial.println("Saturday");
  lcd.setCursor(9,0);
 lcd.print("Sat");
 break;
}
}
void loop(){
// String a="ami";
displayTime(); // display the real-time clock data on the Serial Monitor,
delay(1000); // every second
//lcd.setCursor(0,1);
//lcd.print(b);
lcd.clear();
}
