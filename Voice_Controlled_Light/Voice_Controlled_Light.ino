#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#define light 5
#define WLAN_SSID "xxxxxxxxxx" // Your SSID
#define WLAN_PASS "xxxxxxxxxx" // Your password
/************************* Adafruit.io Setup *********************************/
#define AIO_SERVER "io.adafruit.com" //Adafruit Server
#define AIO_SERVERPORT 1883
#define AIO_USERNAME "xxxxxxxxxxx" // Username
#define AIO_KEY "aio_xxxxxxxxxxxxxxxxxxxxxxxxxxx" // Auth Key
/*AIO_USERNAME AND AIO_KEY will be getting from Adafruit IO by clicking on Key
Symbol.*/
//WIFI CLIENT
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME,
AIO_KEY);
Adafruit_MQTT_Subscribe Light1 = Adafruit_MQTT_Subscribe(&mqtt,
AIO_USERNAME"/feeds/Appliance"); // Feeds name should be same everywhere
void MQTT_connect();
void setup() {
Serial.begin(115200);
pinMode(light, OUTPUT);
// Connect to WiFi access point.
Serial.println(); Serial.println();
Serial.print("Connecting to ");
Serial.println(WLAN_SSID);
WiFi.begin(WLAN_SSID, WLAN_PASS);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println();
Serial.println("WiFi connected");
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
mqtt.subscribe(&Light1);
mqtt.subscribe(&Light2);
}
void loop() {
MQTT_connect();
Adafruit_MQTT_Subscribe *subscription;
while ((subscription = mqtt.readSubscription(20000))) {
if (subscription == &Light1) {
Serial.print(F("Got: "));
Serial.println((char *)Light1.lastread);
int Light1_State = atoi((char *)Light1.lastread);
digitalWrite(light, Light1_State);
}
}
}
void MQTT_connect() {
int8_t ret;
if (mqtt.connected()) {
return;
}
Serial.print("Connecting to MQTT... ");
uint8_t retries = 3;
while ((ret = mqtt.connect()) != 0) {
Serial.println(mqtt.connectErrorString(ret));
Serial.println("Retrying MQTT connection in 5 seconds...");
mqtt.disconnect();
delay(5000);
retries--;
if (retries == 0) {
while (1);
}
}
Serial.println("MQTT Connected!");
}
