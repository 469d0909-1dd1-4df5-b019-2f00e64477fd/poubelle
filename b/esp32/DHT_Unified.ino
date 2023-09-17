// -------------------------> librairies
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <HTTPClient.h>
#include "time.h"
#include "WiFi.h"

// -------------------------> définitions DHT
#define DHTPIN 13
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

// Google Sheets defs
const long  gmtOffset_sec = 19800;
const int   daylightOffset_sec = 0;
const char* ssid = "COVID19 Test Tower";
const char* password = "91DIVOC";
String GOOGLE_SCRIPT_ID = "Google Script ID";

void setup() {
  Serial.begin(115200);
  
  // -------------------------> initialise le DHT
  dht.begin();
  Serial.println("Initialisation, un instant...");
  sensor_t sensor;
  delayMS = sensor.min_delay / 1000;

  // -------------------------> connexion au wifi
  Serial.print("Connexion à ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  // -------------------------> initialise les valeurs
  float temperature = 0;
  float humidite = 0;
  
  // Delay between measurements.
  delay(delayMS);
  
  // -------------------------> obtention température
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("La température ne peut pas être lue!");
  }
  else {
    Serial.print("Température: ");
    Serial.println(event.temperature);
    temperature = event.temperature;
  }
  
  // -------------------------> obtention humidité
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("L'humidité ne peut pas être lue!");
  }
  else {
    Serial.print("Humidité: ");
    Serial.println(event.relative_humidity);
    humidite = event.relative_humidity;
  }

  if(WiFi.status() == WL_CONNECTED){
    // humidite, temperature
    Serial.println("Envoi des données.");
    String urlFinal = "https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?date="+String(humidite)+"&sensor="+String(temperature);
    Serial.print("POST vers Sheets: ");
    Serial.println(urlFinal);
    // -------------------------> envoi des données
    HTTPClient http;
    http.begin(urlFinal.c_str());
    http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
    int httpcode = http.GET();
    Serial.println("HTTP "+httpcode);
    // -------------------------> réponse de google sheets
    String payload;
    if(httpcode > 0){
      payload = http.getString();
      Serial.println("Payload: "+payload);
    }
    // -------------------------> termine la connexion
    http.end();
  } else {
    Serial.println("Non connecté à Internet.");
  }
}
