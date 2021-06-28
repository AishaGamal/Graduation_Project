//#include <OneWire.h> 
//#include <DallasTemperature.h>
//#include <Wire.h>
//#include "MAX30100_PulseOximeter.h"
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

//*************************************************************************************//

#define REPORTING_PERIOD_MS     1000
#define FIREBASE_HOST "potintfirebase-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "MLJqTJYG3Zw5GGKaSnW6NPnNjt35lPXcVDTbVBN1"
#define WIFI_SSID "Matrix"
#define WIFI_PASSWORD "G8s&0ui_NASG.738o4.#a%G@5f"

PulseOximeter pox;
double x;
double y;
const int oneWireBus = 2; 
String myString;

    
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
String myString;
uint32_t tsLastReport = 0;
void onBeatDetected()
{
    Serial.println("Beat!");
}
void setup()
{
    pinMode(D0,OUTPUT);
  Serial.begin(9600);
   Serial.print("Initializing pulse oximeter..");
       if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
   pox.setOnBeatDetectedCallback(onBeatDetected);
  // Start the DS18B20 sensor
  sensors.begin();
   Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    
}
void pulse(){

       pox.update();
       
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
         x=pox.getHeartRate();
         y=pox.getSpO2();
        Serial.print("Heart rate:");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2:");
        Serial.print(pox.getSpO2());
        Serial.println("%");

        tsLastReport = millis();
    }
    }
     void temperature(){

  sensors.requestTemperatures(); 
  float temperatureC = sensors.getTempCByIndex(0);
  float temperatureF = sensors.getTempFByIndex(0);
  Serial.print(temperatureC);
  Serial.println("ºC");
  Serial.print(temperatureF);
  Serial.println("ºF");
  delay(5000);
  
   

   }

void loop() 
{
if(x==0 || y==0)
{
  pulse();
    Firebase.push("pulse/Value1",pox.getHeartRate());
  Firebase.push("pulse/Value",pox.getSpO2());
 
} //delay(5000);
else{
  temperature();
  Firebase.set("Variable/Value",temperatureC);
 Firebase.push("Variable/Value",temperatureC);

}
Serial.println(myString); 

  
}
