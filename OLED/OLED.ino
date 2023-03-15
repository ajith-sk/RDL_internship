#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET 4 // Reset pin
#define SCREEN_ADDRESS 0x3C //0x3C for 128x32pixels OLED
Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,
OLED_RESET);
void setup() {
Serial.begin(9600);
if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) //SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
{
 Serial.println(F("SSD1306 allocation failed"));
 for(;;); // Don't proceed, loop forever
}
}
void loop() {
text();
display.invertDisplay(true);
delay(2000);
display.invertDisplay(false);
delay(2000);
}
void text(void) {
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE); // Draw white text
display.setCursor(5,3); //setting cursor on X Y plane
display.print(F("S.  Ajith  Kumar"));
display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Draw 'inverse' text
display.display();
delay(2000);
}
