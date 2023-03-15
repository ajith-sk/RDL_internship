void setup() {
  Serial.begin(9600);
}

char input = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    input = Serial.read();       // get the character
  
    // check if a number was received
    if ((input >= '0') && (input <= '9')) {
      Serial.print("Number received: ");
      Serial.println(input);
    }
    else if (input == '\n') {        // when we press any no and enter (defaults \n comes).
      Serial.println("Newline");
    }
    else {
      Serial.println("Not a number.");
    }
  } // end: if (Serial.available() > 0)
}
