//Include required libraries
#include "WiFi.h"
#include <HTTPClient.h>
#include "time.h"
const long  gmtOffset_sec = 19800;
const int   daylightOffset_sec = 0;
// WiFi credentials
const char* ssid = "COVID19 Test Tower";         // change SSID
const char* password = "91DIVOC";    // change password
// Google script ID and required credentials
String GOOGLE_SCRIPT_ID = "Google Script ID";    // change Gscript ID
int count = 0;

// READ FROM VALUE
int pin = 39;

void setup() {
  delay(1000);
  Serial.begin(115200);
  delay(1000);
  // connect to WiFi
  Serial.println();
  Serial.print("Connecting to wifi: ");
  Serial.println(ssid);
  Serial.flush();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}
void loop() {
   if (WiFi.status() == WL_CONNECTED) {
    static bool flag = false;
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
      Serial.println("Failed to obtain time");
      return;
    }
    int value = analogRead(pin);
    char timeStringBuff[50]; //50 chars should be enough
    strftime(timeStringBuff, sizeof(timeStringBuff), "%H:%M:%S", &timeinfo); // Epoch time
    String asString(timeStringBuff);
    //asString.replace(" ", "-");
    Serial.print("Time:");
    Serial.println(asString);
    Serial.print("Value:");
    Serial.println(value);
    Serial.print("Count:");
    Serial.println(count);
    String urlFinal = "https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?"+"date=" + String(count) + "&sensor=" + String(value);
    Serial.print("POST data to spreadsheet:");
    Serial.println(urlFinal);
    HTTPClient http;
    http.begin(urlFinal.c_str());
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    int httpCode = http.GET(); 
    Serial.print("HTTP Status Code: ");
    Serial.println(httpCode);
    //---------------------------------------------------------------------
    //getting response from google sheet
    String payload;
    if (httpCode > 0) {
        payload = http.getString();
        Serial.println("Payload: "+payload);    
    }
    //---------------------------------------------------------------------
    http.end();
  }
  count++;
  delay(1000);
} 
