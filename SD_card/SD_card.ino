#include "FS.h"
#include "SD.h"
#include "SPI.h"
void writeFile(fs::FS &fs, const char * path, const char * message){
 Serial.printf("Writing file: %s\n", path);
 File file = fs.open(path, FILE_WRITE);
 if(!file){
 Serial.println("Failed to open file for writing");
 return;
 }
 if(file.print(message)){
 Serial.println("File written");
 } else {
 Serial.println("Write failed");
 }
 file.close();
}
void appendFile(fs::FS &fs, const char * path, const char * message){
 Serial.printf("Appending to file: %s\n", path);
 File file = fs.open(path, FILE_APPEND);
 if(!file){
 Serial.println("Failed to open file for appending");
 return;
 }
 if(file.print(message)){
 Serial.println("Message appended");
 } else {
 Serial.println("Append failed");
 }
 file.close();
}
void readFile(fs::FS &fs, const char * path){
 Serial.printf("Reading file: %s\n", path);
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
void renameFile(fs::FS &fs, const char * path1, const char * path2)
{
 Serial.printf("Renaming file %s to %s\n", path1, path2);
 if (fs.rename(path1, path2))
 {
 Serial.println("File renamed");
 }
 else
 {
 Serial.println("Rename failed");
 }
}
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
 writeFile(SD, "/hello.txt", "Hello ");
 appendFile(SD, "/hello.txt", "World!\n");
 readFile(SD, "/hello.txt");
 deleteFile(SD, "/foo.txt");
 renameFile(SD, "/hello.txt", "/foo.txt");
 readFile(SD, "/foo.txt");
// testFileIO(SD, "/test.txt");
 Serial.printf("Total space: %lluMB\n", SD.totalBytes() / (1024 * 1024));
 Serial.printf("Used space: %lluMB\n", SD.usedBytes() / (1024 * 1024));
}
void loop()
{
}
