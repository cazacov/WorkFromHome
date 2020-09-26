#include <Arduino.h>
#include <WiFi.h>

#include <NTPClient.h>
#include "LedDisplayGFX.h"
#include "credentials.h"

LedDisplay display(28,12);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

int lastMinute = -1;

void showTime() {

  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();
  int seconds = timeClient.getSeconds();

  hours += 2;
  hours %= 24;

  if (seconds & 0x01) {
    display.writePixel(14, 5, 0xF800);
    display.writePixel(14, 7, 0xF800);
  }
  else {
    display.drawPixel(14, 5, 0);
    display.drawPixel(14, 7, 0);
  }
  display.endWrite();

}

void setup() {
  Serial.begin(115200);         
  delay(10);
  Serial.println('\n');

  delay(5000);
  WiFi.begin(ssid, password);             
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());        

  timeClient.begin();
}

void loop() {
  timeClient.update();
  showTime();
  delay(500);
}