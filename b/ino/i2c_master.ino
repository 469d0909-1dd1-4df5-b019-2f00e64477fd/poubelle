/* MASTER */
#include<Wire.h>
#define PIN 9

byte rcvData;
int potValue;

void setup() {
  Wire.begin();
  rcvData = 255;
  pinMode(PIN, OUTPUT);
}

void loop() {
  potValue = analogRead(A0);
  potValue = map(potValue,0,1023,0,255);
  Wire.beginTransmission(0x14);
  Wire.write(potValue);
  Wire.endTransmission();
  Wire.requestFrom(0x14, 1);
  if(Wire.available()){
    rcvData = Wire.read();
  }
  analogWrite(PIN, rcvData);
}
