#include<LiquidCrystal.h> // Include the LCD library
LiquidCrystal lcd(2,15,13,12,14,27); 
void setup() {

  pinMode(25,INPUT);
  Serial.begin(9600);
lcd.begin(16,2); 
}

void loop() {
int a,b;
 b=digitalRead(25);
 if(b==1)

  {
a=random(999,9999);
Serial.println(a);
  lcd.setCursor(0,0); //first line in display
  lcd.print("Random Number:");
    lcd.setCursor(0,1);
lcd.print(a);
delay(2000);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
     lcd.print("Waiting");
     delay(100);
  }
  }
