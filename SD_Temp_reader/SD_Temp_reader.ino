#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include<LiquidCrystal.h> // Include the LCD library
LiquidCrystal lcd(2,15,13,12,14,27); 
const int tempPin = 33; // pin 33 of port P1 connected to LM35 output
int Value,a;
double milivlt,Cel,Far;
void writeFile(fs::FS &fs, const char * path,   String  message){
 //Serial.printf("Writing file: %s\n", path);
 File file = fs.open(path, FILE_WRITE);
 if(!file){
 Serial.println("Failed to open file for writing");
 return;
 }
 if(file.print(message)){
// Serial.println("File written");
 } else {
 //Serial.println("Write failed");
 }
 file.close();
}
//void appendFile(fs::FS &fs, const char * path, const char * message){
// Serial.printf("Appending to file: %s\n", path);
// File file = fs.open(path, FILE_APPEND);
// if(!file){
// Serial.println("Failed to open file for appending");
// return;
// }
// if(file.print(message)){
// Serial.println("Message appended");
// } else {
// Serial.println("Append failed");
// }
// file.close();
//}
void readFile(fs::FS &fs, const char * path){
 //Serial.printf("Reading file: %s\n", path);
 File file = fs.open(path);
 if(!file){
 Serial.println("Failed to open file for reading");
 return;
 }
 Serial.print("Read from file: ");
 while(file.available()){
Serial.write(file.read());
 }
 file.close();
}
//void renameFile(fs::FS &fs, const char * path1, const char * path2)
//{
// Serial.printf("Renaming file %s to %s\n", path1, path2);
// if (fs.rename(path1, path2))
// {
// Serial.println("File renamed");
// }
// else
// {
// Serial.println("Rename failed");
// }
//}
void deleteFile(fs::FS &fs, const char * path)
{
 Serial.printf("Deleting file: %s\n", path);
 if(fs.remove(path)){
 Serial.println("File deleted");
 } else {
 Serial.println("Delete failed");
 }
}
void setup(){
 
 Serial.begin(115200);
 lcd.begin(16,2);
 if(!SD.begin())
 {
 Serial.println("Card Mount Failed");
 return;
 }
 uint8_t cardType = SD.cardType();
 if(cardType == CARD_NONE){
 Serial.println("No SD card attached");
 return;
 }
 Serial.print("SD Card Type: ");
 if(cardType == CARD_MMC)
 {
 Serial.println("MMC");
 } else if(cardType == CARD_SD){
 Serial.println("SDSC");
 } else if(cardType == CARD_SDHC){
 Serial.println("SDHC");
 } else {
 Serial.println("UNKNOWN");
 }
 uint64_t cardSize = SD.cardSize() / (1024 * 1024);
 Serial.printf("SD Card Size: %lluMB\n", cardSize);
 //                                       //writeFile(SD, "/hello.txt",a);
//appendFile(SD, "/hello.txt", "World!\n");
 //                                          readFile(SD, "/hello.txt");
//deleteFile(SD, "/foo.txt");
//                                   //deleteFile(SD, "/hello.txt");
//renameFile(SD, "/hello.txt", "/foo.txt");
// readFile(SD, "/foo.txt");
 Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
 Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
}
void loop()
{Value = analogRead(tempPin); //read sensor output value
milivlt = (Value / 2048.0) * 3300; // converting it to millivots.
Cel = milivlt * 0.1; // calculating temperature in Celsius
Far = (Cel * 1.8) + 32; // convert from C to Fahrenheit
//Serial.print(" Temperature in Celsius = ");
//Serial.print(Cel);
//Serial.print("*C");
lcd.setCursor(0,0);
lcd.print("Temp in *C=");
lcd.setCursor(11,0);
lcd.print(Cel);
//Serial.print("\t Temperature in Fahrenheit = ");
//Serial.print(Far);
//Serial.println("*F");
lcd.setCursor(0,1);
lcd.print("Temp in *F=");
lcd.setCursor(11,1);
lcd.print(Far);
String Farr,farr;
 Farr=String(Far,2);
 
writeFile(SD, "/hello.txt",Farr);
readFile(SD, "/hello.txt");
Serial.println("*F");
delay(2000); 


}
