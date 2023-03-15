const int  L6=5; //initializing LED pins
void setup()
{
//pinMode(L5, OUTPUT);
pinMode(L6, OUTPUT);

}

void loop2() {
digitalWrite(L6, HIGH);
delay(1000);
digitalWrite(L6, LOW);
delay(1000);
}
