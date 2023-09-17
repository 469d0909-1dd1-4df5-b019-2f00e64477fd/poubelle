const int ledPIN = 2;
const int ledPIN2 = 27;

int dutyCycle;
const int PWMFreq = 5000;
const int PWMChannel = 0;
const int PWMChannel2 = 2;
const int PWMResolution = 10;
const int MAX_DUTY_CYCLE = (int)(pow(2, PWMResolution));

void setup() {
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcSetup(PWMChannel2, PWMFreq, PWMResolution);
  ledcAttachPin(ledPIN, PWMChannel);
  ledcAttachPin(ledPIN2, PWMChannel2);
}

void loop() {
  for(dutyCycle = 0; dutyCycle <= MAX_DUTY_CYCLE; dutyCycle++){
    ledcWrite(PWMChannel, dutyCycle);
    ledcWrite(PWMChannel2, dutyCycle);
    delay(3);
  }
  for(dutyCycle = MAX_DUTY_CYCLE; dutyCycle >= 0; dutyCycle--){
    ledcWrite(PWMChannel, dutyCycle);
    ledcWrite(PWMChannel2, dutyCycle);
    delay(3);
  }
}
