#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

/* WiFi */
#define WIFI_SSID "COVID19 Test Tower"
#define WIFI_PASSWORD "91DIVOC"

/* Clé d'API Firebase */
#define API_KEY "0123456789"

/* URL de la RTDB */
#define DATABASE_URL "https://www.youtube.com/watch?v=x31tDT-4fQw" 

/* Pins des composants */
#define LED1 26
#define LED2 27
#define PHOTORES 36
#define BUTTON 4
int etat_button = 0;

/* Paramètres du programme */
#define DISPLAY_LAST_RECORD true // Récupère les données de l'enregistrement déjà existant dans Firebase.
#define TIMEOUT_BETWEEN_RECORD 7 // Délai entre chaque enregistrement, en secondes
#define DISPLAY_TBR true         // Afficher le délai entre chaque enregistrement, avec un point par seconde.
#define DISPLAY_BUTTON true      // Afficher l'état du bouton entre chaque enregistrement, si celui-ci est sauvegardé dans Firebase.

/* Define Firebase Data object */
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

/* LEDs (1: allumé, 0: éteint) */
int led1_state = 0;
int led2_state = 0;

void setup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connexion au réseau Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connecté au réseau. IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assigne la clé d'API (obligatoire) */
  config.api_key = API_KEY;

  /* Assigne l'URL de la RTDB (obligatoire) */
  config.database_url = DATABASE_URL;

  /* Connexion à Firebase */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("Connecté à Firebase");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  /* Configure le mode des PINs des composants */
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(PHOTORES, INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop(){

  /* Récupère l'état du bouton, l'enregistre et l'affiche (en option) */
  etat_button = digitalRead(BUTTON);
  if (Firebase.RTDB.setInt(&fbdo, "test/bouton", led1_state)){
  } else {
    Serial.println("Échec écriture état du bouton: " + fbdo.errorReason());
  }
  if(DISPLAY_BUTTON == true){
    Serial.print("État du bouton "); Serial.println(etat_button);
  }

  /* Affiche le temps d'attente entre chaque enregistrement */
  if(DISPLAY_TBR == true) {
    Serial.print(TIMEOUT_BETWEEN_RECORD);
    Serial.print(" secondes");
    for(int i = TIMEOUT_BETWEEN_RECORD; i > 0; i--){
      Serial.print('.');
      delay(1000);
    }
    Serial.println('!');
  }
  
  if (etat_button == HIGH && Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > (TIMEOUT_BETWEEN_RECORD*1000) || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();

    /* Récupère l'enregistrement actuel */
    if (DISPLAY_LAST_RECORD == true) {
      lire_enregistrement_precedent();
    }
    
    /* Écrit le numéro de l'enregistrement */
    Serial.print("================ ENREGISTREMENT "); Serial.print(count); Serial.println(" ================");
    if (Firebase.RTDB.setInt(&fbdo, "test/int", count)){
      Serial.println("Succès");
      //Serial.println("Path: " + fbdo.dataPath());
      //Serial.println("Type: " + fbdo.dataType());
    }
    else {
      Serial.println("Échec");
      Serial.println("Raison: " + fbdo.errorReason());
    }
    count++;

    /* Modification des états des LED */
    if(led1_state == 0){
      digitalWrite(LED1, HIGH);
      led1_state = 1;
    } else {
      digitalWrite(LED1, LOW);
      led1_state = 0;
    }
    if(led2_state == 0){
      digitalWrite(LED2, HIGH);
      led2_state = 1;
    } else {
      digitalWrite(LED2, LOW);
      led2_state = 0;
    }

    /* Écriture des états des LEDs */
    if (Firebase.RTDB.setInt(&fbdo, "test/led1", led1_state)){
      Serial.println("État LED 1 écrit");
    } else {
      Serial.println("Échec écriture état LED 1: " + fbdo.errorReason());
    }
    if (Firebase.RTDB.setInt(&fbdo, "test/led2", led1_state)){
      Serial.println("État LED 2 écrit");
    } else {
      Serial.println("Échec écriture état LED 2: " + fbdo.errorReason());
    }

    /* Écriture de la valeur de la photorésistance */
    int valeur = analogRead(PHOTORES);
    //float valeur_voltage = (valeur/4095)*5;

    if (Firebase.RTDB.setInt(&fbdo, "test/pr", valeur)) {
      Serial.print("Valeur PHOTORES: ");
      Serial.println(valeur);
    } else {
      Serial.println("Échec écriture valeur écrite: " + fbdo.errorReason());
    }
    
    /* Écrit un nombre aléatoire entre 0 et 1 */
    /*if (Firebase.RTDB.setFloat(&fbdo, "test/float", 0.01 + random(0,100))){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }*/
  }
}

void lire_enregistrement_precedent() {
  sendDataPrevMillis = millis();
  if (Firebase.RTDB.getInt(&fbdo, "/test/int")) {
    if (fbdo.dataType() == "int") {
      Serial.print("Données de l'enregistrement "); Serial.print(fbdo.intData()); Serial.println(" à partir de Firebase:");
    }
  }
  if (Firebase.RTDB.getInt(&fbdo, "/test/led1")) {
    if (fbdo.dataType() == "int") {
      Serial.print("LED1: "); Serial.println(fbdo.intData());
    }
  }
  if (Firebase.RTDB.getInt(&fbdo, "/test/led2")) {
    if (fbdo.dataType() == "int") {
      Serial.print("LED2: "); Serial.println(fbdo.intData());
    }
  }
  if (Firebase.RTDB.getInt(&fbdo, "/test/pr")) {
    if (fbdo.dataType() == "int") {
      Serial.print("Photorésistance: "); Serial.println(fbdo.intData());
    }
  }
}
