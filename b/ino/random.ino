void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop(){
  Serial.println(random(1,100));
  delay(1000);
}
