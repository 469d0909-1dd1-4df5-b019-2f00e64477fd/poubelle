//
//
#define TRIG 12
#define ECHO 11

float distance_cm;
float vitesse_son;
float vitesse_son_cm;
float distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // Calcul temps
  long duree_echo = pulseIn(ECHO, HIGH);
  float echo = duree_echo/2; // retour seulement
  
  // Vitesse
  distance_cm = 50; // d/T
  distance = distance_cm/100;
  vitesse_son = distance/echo*1000000; // distance/temps en cm/µs
  
  // Print distance
  Serial.print("Distance = ");
  Serial.print(distance_cm);
  Serial.print("cm \t");
  
  // Print temps
  Serial.print("Temps = ");
  Serial.print(echo);
  Serial.print("µs \t");
  
  // Print vitesse son
  Serial.print("Vitesse son = ");
  Serial.print(vitesse_son);
  Serial.println("m/s");
  
  delay(1000);
}
