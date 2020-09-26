#include <Arduino.h>
#include <WiFi.h>

#include <NTPClient.h>
#include "LedDisplayGFX.h"
#include "credentials.h"

LedDisplayGFX display(28,12);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

int lastMinute = -1;

void showTime() {

  int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();
  int seconds = timeClient.getSeconds();

  hours += 1;
  hours %= 24;

  if (seconds & 0x01) {
    display.writePixel(14, 4, 0xF800);
    display.writePixel(14, 6, 0xF800);
  }
  else {
    display.drawPixel(14, 4, 0);
    display.drawPixel(14, 6, 0);
  }
  display.endWrite();

  
  if (minutes != lastMinute) {
    display.setTextColor(0xF800);
    String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);
    String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);

    display.fillRect(1, 2, 26, 10, 0);

    display.setCursor(2, 2);   
    display.print(hoursStr);

    display.setCursor(16, 2);   
    display.print(minuteStr);
    lastMinute = minutes;
  }

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
  delay(200);
}