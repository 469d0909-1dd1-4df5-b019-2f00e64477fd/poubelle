#define PIR 13
#define LED 12

void setup() {
	pinMode(PIR, INPUT);
	pinMode(LED, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	int valeurPIR = digitalRead(PIR);
	Serial.println(valeurPIR);
	if(valeurPIR == 1){
		digitalWrite(LED, HIGH);
	} else {
		digitalWrite(LED, LOW);
	}
	delay(250);
}
