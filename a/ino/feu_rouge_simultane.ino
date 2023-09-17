void setup()
{
  pinMode(13, OUTPUT); // rouge 1
  pinMode(12, OUTPUT); // jaune 1
  pinMode(11, OUTPUT); // vert  1
  pinMode(10, OUTPUT); // rouge 2
  pinMode(9, OUTPUT);  // jaune 2
  pinMode(8, OUTPUT);  // vert  2
  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  
  Serial.begin(9600);
}

void loop()
{
  // délais
  int normalDelay = 2000;
  int jauneDelay = 500;
  
  // cas 1: feu 1 rouge, feu 2 vert
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  Serial.println("2R 1V");
  delay(normalDelay);
  
  // cas 2: feu 1 rouge, feu 2 jaune
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  Serial.println("2R 1J");
  delay(jauneDelay);
  
  // cas 3: feu 1 vert, feu 2 rouge
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(11, HIGH);
  Serial.println("2V 1R");
  delay(normalDelay);
  
  // cas 4: feu 1 jaune, feu 2 rouge
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  Serial.println("2J 1R");
  delay(jauneDelay);
}
