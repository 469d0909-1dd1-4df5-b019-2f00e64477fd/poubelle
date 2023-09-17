//
//
#define bouton 3

int etat;
int oldEtat;
const int WAIT = 2;
const int START = 1;
const int STOP = 0;

void setup() {
  oldEtat = LOW;
  etat = WAIT;
  Serial.begin(19200);
  pinMode(bouton, INPUT);
}

void loop() {
  int etatbouton = digitalRead(bouton);
  if(oldEtat == LOW && etatbouton == HIGH){
    if(etat == WAIT){
      etat = START;
    }
    else if(etat == STOP){
      etat = START;
    }
    else if(etat == START){
      etat = STOP;
    }
  }
  if(etat == START){
    int valeur = analogRead(A0);
    Serial.print(valeur);
    Serial.print("\t");
    Serial.println(millis());
  }
  oldEtat = etatbouton;
  delay(10);
}
