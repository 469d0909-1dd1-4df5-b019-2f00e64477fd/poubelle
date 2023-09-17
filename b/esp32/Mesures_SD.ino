#include<SD.h>
#include<SPI.h>

File myFile;

int pinCS = 10;
int i = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  if(SD.begin()){
    Serial.println("SD prete a etre utilisée");
  } else {
    Serial.println("SD non initialisée");
  }
  myFile = SD.open("Test.txt", FILE_WRITE);
  if(myFile){
    myFile.print("Temps [ms] \t Valeur [V]\n");
    Serial.println("écrit");
  } else {
    Serial.println("Erreur d'ouverture du fichier.");
  }
  delay(1000);
  myFile.close();

  // 20 enregistrements
  while(i < 20){
    myFile = SD.open("Test.txt", FILE_WRITE);
    if(myFile){
      Serial.print("Mesure ");
      Serial.print(i);
      unsigned long temps = millis();
      int valeur = analogRead(A0);
      float valeur2 = (valeur*5.0)/1023.0;
      Serial.print("\t");
      Serial.println(valeur2);
      myFile.print(temps);
      myFile.print("\t");
      myFile.println(valeur2);
      i++;
    } else {
      Serial.println("Erreur d'ouverture du fichier!");
    }
    myFile.close();
    delay(1000);
  }
}

void loop() { }
