const int Switch[8]={34, 35, 32, 33, 36, 39, 25, 26}; //declaring DIP Switches(Port P1)
const int Led[8]={23, 22, 21, 19, 18, 5, 17, 16}; //declaring LEDs (Port P2)
void setup()
{
for(int i=0;i<8;i++)
{
 pinMode(Switch[i],INPUT);
 pinMode(Led[i],OUTPUT);
 delay(20);
}
}
void loop()
{
for(int i=0; i<8;i++)
{
digitalWrite(Led[i],digitalRead(Switch[i])); // Reads the state of each switches and replicate it on LEDs
}
delay(1000);
}
