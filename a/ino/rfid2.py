# Une meilleure version du RFID.py
import RPi.GPIO as GPIO
from pirc522 import RFID
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

rc522 = RFID()

rfid_uid = [0, 0, 0, 0, 0] #Ajoutez l'ID du bon badge ici

# Pins des LEDs et du servo
LED_RED      = 3
LED_GREEN    = 5
SERVO_ORANGE = 38
SERVO_RED    = 36
SERVO_PWM    = 11

# Pour le servo, apparemment
frequence = 50

# Init le moteur
GPIO.setup(SERVO_PWM, GPIO.OUT)
pwm = GPIO.PWM(PWM_GPIO, frequence)

# Gérer le moteur (Servo.py)
def angle_to_percent(angle):
	if angle > 180 or angle < 0:
		return False
	
	start = 4
	end = 12.5
	ratio = (end-start)/180
	
	angle_as_percent = angle * ratio
	return angle_as_percent

# Alluer une LED
def turn_on_led(led):
	GPIO.setup(led, GPIO.OUT)
	GPIO.output(led, GPIO.HIGH)

# Éteint une LED
def turn_off_led(led):
	GPIO.setup(led, GPIO.OUT)
	GPIO.output(led, GPIO.LOW)

# Allume la rouge
def turn_red_on():
	turn_on_led(LED_RED)
	turn_off_led(LED_GREEN)

# Allume la verte
def turn_green_on():
	turn_on_led(LED_GREEN)
	turn_off_led(LED_RED)

# Ici, le servo aura pour but d'imiter une serrure de porte.
while True:
		pwm.start(angle_to_percent(0))
		rc522.wait_for_tag() # Attend le badge
		(error, tag_type) = rc522.request()
		if not error:
			(error, uid) = rc522.anticoll() # On pourra pas en passer 2 à la fois
			if not error:
				print('Badge présenté: {}'.format(uid))
				if(uid == rfid_uid):
					print('Bon badge.')
					pwm.ChangeDutyCycle(angle_to_percent(90)) # Ouvre la porte
					turn_green_on() # Allume la LED pour indiquer le bon badge
					time.sleep(5) # Garde la porte ouverte pour 5 secondes
				
				else:
					print('Mauvais badge.')
					turn_red_on() # Allume la LED pour informer que le badge est mauvais
					time.sleep(1) # Attend une seconde pour pas flood
				
				turn_off_led(LED_RED)
				turn_off_led(LED_GREEN)
