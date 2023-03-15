const int tempPin = 33; // pin 33 of port P1 connected to LM35 output
int Value,a;
double milivlt,Cel,Far;
void setup()
{
Serial.begin(9600);
pinMode(4,OUTPUT);
}

void loop()
{
Value = analogRead(tempPin); //read sensor output value
milivlt = (Value / 2048.0) * 3300; // converting it to millivots.
Cel = milivlt * 0.1; // calculating temperature in Celsius
Far = (Cel * 1.8) + 32; // convert from C to Fahrenheit
Serial.print(" Temperature in Celsius = ");
Serial.print(Cel);
Serial.print("*C");
Serial.print("\t Temperature in Fahrenheit = ");
Serial.print(Far);
Serial.println("*F");
delay(1000); 
if(Far>102)
{
digitalWrite(4,HIGH);
delay(2000);
digitalWrite(4,LOW);
delay(1000);
}

}
