#include <OneWire.h>
#include <DallasTemperature.h>
#include <SD.h>
#include <SPI.h>
 
const int chipSelect = 4;
 
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
// Setup a oneWire instance to communicate with any OneWiredevices 
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass the oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
 
// Setup instructions run at startup
void setup(void)
{
  // Start serial port
  Serial.begin(9600);
 
  // SD card setup
 Serial.print("Initializing SD card...");
 
  // Make sure thatthe default chip select pin is set to output
  pinMode(10, OUTPUT);
 
  // Check if the cardis present and can be initialized:
  if(!SD.begin(chipSelect)) {
   Serial.println("SD card initialization failed, or notpresent");
    return;
  }
 Serial.println("SD card initialized.");
 
  // Sensor: start upthe library
  sensors.begin();
 
}
 
 
// Main loop
void loop(void)
{
  // Read thetemperature: request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0));
 
  // Prepare string to be saved on file
  String dataString ="";
  dataString +=sensors.getTempCByIndex(0); 
 
  // Open the file
  File dataFile =SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
   dataFile.println(dataString);
   dataFile.close();
   // Print to theserial port too:
   Serial.println(dataString);
  }  
 
  // If the file isn'topen, issue an error:
  else {
   Serial.println("error opening datalog.txt");
  } 
 
  // Wait 60 seconds
  delay(60000);
}
