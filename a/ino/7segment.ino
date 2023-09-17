//
//
int count = 0;

void setup()
{
  // NE PAS FAIRE DE BOUCLE FOR
  pinMode(3, OUTPUT); // A - Haut
  pinMode(4, OUTPUT); // B - Haut à droite
  pinMode(5, OUTPUT); // F - Haut à gauche
  pinMode(6, OUTPUT); // G - Milieu
  pinMode(7, OUTPUT); // C - Bas à droite
  pinMode(8, OUTPUT); // D - Bas
  pinMode(9, OUTPUT); // E - Bas à gauche
  pinMode(13, INPUT); // bouton
  Serial.begin(9600);
  clearDisplay();
}

void loop()
{
  int button = 0;
  button = digitalRead(13);
  
  if(button == 1){
    
    // 1
    if(count == 0){
      clearDisplay();
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      count++;
    }
    
    // 2
    else if(count == 1){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      count++;
    }
    
    // 3
    else if(count == 2){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      count++;
    }
    
    // 4
    else if(count == 3){
      clearDisplay();
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      count++;
    }
    
    // 5
    else if(count == 4){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      count++;
    }
    
    // 6
    else if(count == 5){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      count++;
    }
    
    // 7
    else if(count == 6){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(7, HIGH);
      count++;
    }
    
    // 8
    else if(count == 7){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      count++;
    }
    
    // 9
    else if(count == 8){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      count++;
    }
    
    // 0
    else if(count == 9){
      clearDisplay();
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      count = 0;
    }
  }
}

void clearDisplay() {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.println("Cleared!");
}
