import RPi.GPIO as GPIO
import time

def angle_to_percent(angle):
	if angle > 180 or angle < 0:
		return False
	
	start = 4
	end = 12.5
	ratio = (end-start)/180
	
	angle_as_percent = angle * ratio
	return angle_as_percent

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

PWM_GPIO = 11 # pin n°11, GPIO 17
frequence = 50
GPIO.setup(PWM_GPIO, GPIO.OUT)
pwm = GPIO.PWM(PWM_GPIO, frequence)

# Initialisation à 0°
pwm.start(angle_to_percent(0))
print("0°")
time.sleep(1)

# 90°
pwm.ChangeDutyCycle(angle_to_percent(90))
print("90°")
time.sleep(1)

# 180°
pwm.ChangeDutyCycle(angle_to_percent(180))
print("180°")
time.sleep(1)

# Nettoyage
pwm.stop()
GPIO.cleanup()
