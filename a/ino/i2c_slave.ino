/* Slave I2C */
#include <Wire.h>
#define ledPin 9

byte rcvData;
int potValue;

void setup() {
  Wire.begin(0x14);
  /* Event listeners */
  Wire.onReceive(DataReceive);
  Wire.onRequest(DataRequest);
  
  rcvData = 255;
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(A0);
  potValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, rcvData);
  Serial.println(potValue);
}

void DataReceive(int numBytes) {
  while(Wire.available()){
    rcvData = Wire.read();
  }
}

void DataRequest() {
  Wire.write(potValue);
}
