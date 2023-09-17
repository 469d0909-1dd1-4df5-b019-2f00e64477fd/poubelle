#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

/*Définit les pins du Servo, le Slave Select et le Reset du RFID*/
#define PIN_SERVO 4
#define PIN_SS 10
#define PIN_RESET 99

int angle_servo;

/*Instances pour le servo et le RFID*/
Servo servo;
MFRC522 mfrc522(PIN_SS, PIN_RESET);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  myservo.attach(PIN_SERVO);
  myservo.write(0); // Initialise le servo à 0°
  Serial.println("Initialisation");
  
}

void loop() {
  Serial.print("Angle de rotation:");
  angle_servo = 90;
  Serial.print("\t Angle servo:");
  Serial.println(angle_servo);
  servo.write(angle_servo);
  delay(5000);
  angle_servo = 0;
  servo.write(angle_servo);
}
