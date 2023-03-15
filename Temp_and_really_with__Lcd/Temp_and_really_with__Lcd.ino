#include<LiquidCrystal.h> 
const int tempPin = 33; // pin 33 of port P1 connected to LM35 output
int Value,a;
double milivlt,Cel,Far;
LiquidCrystal lcd(16,17,19,21,22,23);
void setup()
{
Serial.begin(9600);
pinMode(4,OUTPUT);
lcd.begin(16,2);
}


void displayTime(){

Value = analogRead(tempPin);          //read sensor output value
milivlt = (Value / 2048.0) * 3300;    // converting it to millivots.
Cel = milivlt * 0.1;                  // calculating temperature in Celsius
Far = (Cel * 1.8) + 32;               // convert from C to Fahrenheit
 
Serial.print(" Temperature in Celsius = ");
Serial.print(Cel);
Serial.print("*C");

lcd.setCursor(0,0);
lcd.print("Temp_*C= ");
lcd.print(Cel);



Serial.print("\t Temperature in Fahrenheit = ");
Serial.print(Far);
Serial.println("*F");

lcd.setCursor(0,1);
lcd.print("Temp_*F= ");
lcd.print(Far);

delay(1000); 

if(Far>102)
{
digitalWrite(4,HIGH);
//lcd.print("Temp in *C =");
//lcd.print(Cel);
delay(2000);

digitalWrite(4,LOW);
//lcd.print("Temp in *F =");
//lcd.print(Far);
delay(1000);
}
  
}





void loop()
{
displayTime();
delay(1000);
}
