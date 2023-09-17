#include<SD.h>
#include<SPI.h>

File myFile;

int pinCS = 10; // pin 53 sur les Mega

void setup() {
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);
  pinMode(A0, INPUT);

  // Initialise la carte SD
  if(SD.begin()){
    Serial.println("Carte SD prête");
  } else {
    Serial.println("Carte SD non initialisée");
    return;
  }

  myFile = SD.open("Test.txt", FILE_WRITE);

  // Si le fichier est ouvert, on écrit
  if(myFile){
    Serial.println("Écriture...");
    myFile.println("Temps\tTension (mV)");
    unsigned long temps;
    for(int i = 0; i<11; i++){
      temps = millis();
      myFile.print(temps);
      myFile.print("\t\t");
      myFile.println(analogRead(A0));
    }
    myFile.close();
    Serial.println("Terminé.");
  } else {
    Serial.println("Fichier non ouvert.");
    return;
  }

  // Lecture
  myFile = SD.open("Test.txt");
  if(myFile){
    Serial.println("Lecture");
    while(myFile.available()){
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("Fichier non lu.");
  }
}

void loop() {
  // LAISSEZ VIDE
}
