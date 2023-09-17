#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth désactivé - Lancer "make menuconfig" pour l'activer!
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("esp32 wish quality");
  Serial.println("Bluetooth démarré; pret a accoupler");
}

void loop() {
  if(Serial.available()){
    SerialBT.write(Serial.read());
  } else {
    Serial.write(SerialBT.read());
  }
  delay(100);
}
