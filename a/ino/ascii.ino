//
//
void setup(){
  Serial.begin(115200);
}

void loop(){
  
  int i = 65;
  // En ASCII, A est le 65e caractère
  // Jusqu'à 90: Z
  
  while(i<91){
  	char lettre = i;
    Serial.print("i="); Serial.print(i);
    Serial.print(" / ");
    Serial.println(lettre);
    i++;
    delay(125);
  }
  delay(3000);
  
}
