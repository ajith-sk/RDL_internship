const int L1=23, L2=22, L3=21, L4=19, L5=18, L6=5, L7=17, L8=16; //initializing LED pins
void setup()
{
pinMode(L1, OUTPUT); // Set all Port P2 pins as output
pinMode(L2, OUTPUT);
pinMode(L3, OUTPUT);
pinMode(L4, OUTPUT);
pinMode(L5, OUTPUT);
pinMode(L6, OUTPUT);
pinMode(L7, OUTPUT);
pinMode(L8, OUTPUT);
}
void loop()
{
digitalWrite(L1, HIGH);
digitalWrite(L2, HIGH);
digitalWrite(L3, HIGH);
digitalWrite(L4, HIGH);
digitalWrite(L5, HIGH);
digitalWrite(L6, HIGH);
digitalWrite(L7, HIGH);
digitalWrite(L8, HIGH);
delay(200);
digitalWrite(L1, LOW);
digitalWrite(L2, LOW);
digitalWrite(L3, LOW);
digitalWrite(L4, LOW);
digitalWrite(L5, LOW);
digitalWrite(L6, LOW);
digitalWrite(L7, LOW);
digitalWrite(L8, LOW);
delay(200);
}
