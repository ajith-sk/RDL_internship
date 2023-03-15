/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>

#include <Blynk.h>

#include <Servo.h>

char auth[] = "J-VtmKl4-1GpEizdX7sIiodcfd8h4wvr";

char ssid[] = "sysk";
char pass[] = "123456789";


Servo servo;

BLYNK_WRITE(V3) {

servo.write(param.asInt());

}

void setup() {

// Debug console Serial.begin(115200);

Blynk.begin(auth, ssid, pass);

Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);

Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);

servo.attach(15); // 15 means D8 pin of ESP8266

}

void loop()

{

Blynk.run(); .

}
