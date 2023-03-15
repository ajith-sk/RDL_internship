#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

/*
#define BLYNK_TEMPLATE_ID "TMPL2uQRQNj_"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "VeJcID-ob5i-Up2wMHmh1_zi16p--s1I"  
*/



#define BLYNK_TEMPLATE_ID "TMPLZTVYrR5w"
#define BLYNK_TEMPLATE_NAME "Motor"
#define BLYNK_AUTH_TOKEN "Pq6ODjMiLOkx2LXsEJ3q4XT5EJB0HS80"





/* Comment this out to disable prints and save space */
char auth[] = "Pq6ODjMiLOkx2LXsEJ3q4XT5EJB0HS80";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "sysk";
char pass[] = "123456789";



void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop()
{
  Blynk.run();
}
