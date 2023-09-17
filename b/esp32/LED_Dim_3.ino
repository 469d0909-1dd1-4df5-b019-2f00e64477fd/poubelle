const int rougepin = 16;
const int vertpin = 17;
const int jaunepin = 5;
uint16_t rougeDutyCycle;
uint16_t vertDutyCycle;
uint16_t jauneDutyCycle;
const int rougePWMFreq = 5000;
const int rougePWMChannel = 0;
const int rougePWMRes = 12;
const int rougeMaxDutyCycle = (int)(pow(2, rougePWMRes) - 1);
const int jaunePWMFreq = 5000;
const int jaunePWMChannel = 2;
const int jaunePWMRes = 12;
const int jauneMaxDutyCycle = (int)(pow(2, rougePWMRes) - 1);
const int vertPWMFreq = 5000;
const int vertPWMChannel = 4;
const int vertPWMRes = 12;
const int vertMaxDutyCycle = (int)(pow(2, rougePWMRes) - 1);
const int ADC_RESOLUTION = 4095;

void setup() {
  Serial.begin(115200);
  ledcSetup(rougePWMChannel, rougePWMFreq, rougePWMRes);
  ledcSetup(jaunePWMChannel, jaunePWMFreq, jaunePWMRes);
  ledcSetup(vertPWMChannel, vertPWMFreq, vertPWMRes);
  ledcAttachPin(rougepin, rougePWMChannel);
  ledcAttachPin(jaunepin, jaunePWMChannel);
  ledcAttachPin(vertpin, vertPWMChannel);
}

void loop() {
  rougeDutyCycle = analogRead(A0);
  vertDutyCycle = analogRead(A3);
  jauneDutyCycle = analogRead(A4);
  rougeDutyCycle = map(rougeDutyCycle, 0, ADC_RESOLUTION, 0, rougeMaxDutyCycle);
  vertDutyCycle = map(vertDutyCycle, 0, ADC_RESOLUTION, 0, vertMaxDutyCycle);
  jauneDutyCycle = map(jauneDutyCycle, 0, ADC_RESOLUTION, 0, jauneMaxDutyCycle);
  ledcWrite(rougePWMChannel, rougeDutyCycle);
  ledcWrite(jaunePWMChannel, jauneDutyCycle);
  ledcWrite(vertPWMChannel, vertDutyCycle);
  Serial.println("ROUGE -- VERT -- JAUNE");
  Serial.print(rougeDutyCycle);
  Serial.print(" -- ");
  Serial.print(jauneDutyCycle);
  Serial.print(" -- ");
  Serial.println(vertDutyCycle);
  delay(2000);
}
