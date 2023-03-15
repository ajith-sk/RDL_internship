
int o1=19,o2=21,o3=22,o4=23,en1=05,en2=18;
const int tempPin = 33; // pin 33 of port P1 connected to LM35 output
int Value,a;
double milivlt,Cel,Far;


const int freq= 5000; // 5000 Hz
const int ledChannel= 0;

const int resolution = 8;
void setup() {
  Serial.begin(9600);
    ledcSetup(ledChannel, freq, resolution);
 
 ledcAttachPin(19, ledChannel);
 
  // put your setup code here, to run once:
pinMode(19,OUTPUT);
pinMode(21,OUTPUT);
pinMode(22,OUTPUT);
pinMode(23,OUTPUT);
pinMode(05,OUTPUT);
pinMode(18,OUTPUT);
ledcAttachPin(o1, ledChannel);

}

void loop() {
     digitalWrite(en1,HIGH);
    digitalWrite(en2,HIGH);
    digitalWrite(o3,LOW);
      digitalWrite(o4,LOW);
    
// ledcWrite(ledChannel,150);
// digitalWrite(o2,LOW);
//delay(2000);
// ledcWrite(ledChannel,255);
//digitalWrite(o2,LOW);
//delay(2000);
// ledcWrite(ledChannel,0);
//digitalWrite(o2,HIGH);
//delay(2000);
// ledcWrite(ledChannel,50);
//digitalWrite(o2,HIGH);
//delay(2000);
      
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

if(Far>103)
{
 ledcWrite(ledChannel,255);
digitalWrite(o2,LOW);
}
else{
 ledcWrite(ledChannel,150);
 digitalWrite(o2,LOW);
}
}
