#include<LiquidCrystal.h> 
LiquidCrystal lcd(16,17,19,21,22,23);                 // Set all Port P2 pins as output
//const int L1=16, L2=17, L3=5, L4=18, L5=19, L6=21, L7=22, L8=23;
const int L1=4, L2=0, L3=2, L4=15, L5=13, L6=12, L7=14, L8=27;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(L1, OUTPUT); // Set all Port P3 pins as output
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
}

char input = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    input = Serial.read();       // get the character
  
    // check if a number was received
    if (input == '1') {
      digitalWrite(L1, HIGH);
      digitalWrite(L2, HIGH);
      digitalWrite(L3, HIGH);
      digitalWrite(L4, HIGH);
      digitalWrite(L5, HIGH);
      digitalWrite(L6, HIGH);
      digitalWrite(L7, HIGH);
      digitalWrite(L8, HIGH);
      Serial.println("LED ON");
      lcd.setCursor(0,0);
      lcd.print("LED ON");
    }
    else if (input == '0') {        // when we press any no and enter (defaults \n comes).
      digitalWrite(L1, LOW);
      digitalWrite(L2, LOW);
      digitalWrite(L3, LOW);
      digitalWrite(L4, LOW);
      digitalWrite(L5, LOW);
      digitalWrite(L6, LOW);
      digitalWrite(L7, LOW);
      digitalWrite(L8, LOW);
      Serial.println("LED OFF");
      lcd.setCursor(0,0); 
      lcd.print("LED OFF");
    }
    else if ((input > '0') && (input < '9')) {
      lcd.setCursor(0,0);
      
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
      
      Serial.println("Invalid Input");
      lcd.println("Invalid Input");
      
    }
  } 
}
