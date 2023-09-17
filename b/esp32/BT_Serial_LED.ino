int ledPIN = 2;
int ledPIN2 = 27;
BluetoothSerial SerialBT;
byte BTData;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth désactivé - Exécuter "make menuconfig" et l'activer...
#endif

void setup() {
  pinMode(ledPIN, OUTPUT);
  pinMode(ledPIN2, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("esp32 wish");
  Serial.println("Bluetooth démarré - pret a coupler");
}

void loop() {
  if(SerialBT.available()){
    BTData = SerialBT.read();
    Serial.write(BTData);
  }

  if(BTData == '2'){
    digitalWrite(ledPIN2, HIGH);
  }
  if(BTData == '1'){
    digitalWrite(ledPIN, HIGH);
  }
  if(BTData == '0'){
    digitalWrite(ledPIN, LOW);
    digitalWrite(ledPIN2, LOW);
  }
}
