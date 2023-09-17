#include<SPI.h>
#define LED 7
#define BUTTON 2
int buttonvalue;
int x;

void setup() {
  Serial.begin(115200);
  
  // Définit les PINs
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, OUTPUT);
  
  // Démarre SPI
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  
  // Règle SlaveSelect > HIGH
  digitalWrite(SS, HIGH);
}

void loop() {
  byte Mastersend, Masterreceive;
  
  // Lit l'état de la pin 2
  buttonvalue = digitalRead(BUTTON);
  
  if(buttonvalue == HIGH){
    x = 1;
  } else {
    x = 0;
  }
  
  // Démarre la communication avec l'Esclave (MOSI)
  digitalWrite(SS, LOW);
  
  // Envoie la valeur à l'esclave
  Mastersend = x;
  Masterreceive = SPI.transfer(Mastersend);
  
  if(Masterreceive == 1){
    digitalWrite(LED, HIGH);
    Serial.println("Master LED ON");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("Master LED OFF");
  }
  delay(1000);
  
}
