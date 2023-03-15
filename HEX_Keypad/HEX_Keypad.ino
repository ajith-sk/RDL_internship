#include <Keypad.h>
char keys[4][4]={ {'1','2','3','4'},{'5','6','7','8'},{'9','0','A','B'},{'C','D','E','F'}}; //defining characters of 4X4 Key Matrix
byte rowPin[4]={16,17,5,18}; //declaring the rows and column pins (Port P2)
byte colPin[4]={19,21,22,23};
Keypad keypad=Keypad(makeKeymap(keys),rowPin,colPin,4,4); // Creating 4X4 Keypad Matrix
void setup()
{
Serial.begin(9600);
}
void loop()
{
char pressed=keypad.getKey(); //This function will fetch the character being pressed
if(pressed)
{
Serial.print("Key pressed = ");
Serial.println(pressed);
}
delay(10);
}
