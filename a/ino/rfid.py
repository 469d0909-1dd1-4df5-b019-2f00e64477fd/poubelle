import RPi.GPIO as GPIO
import time
from pirc522 import RFID

# Setup
GPIO.setmode(GPIO.BOARD)
rc522 = RFID() # Nouvelle instance

def comparer_liste(l1, l2):
	l1.sort()
	l2.sort()
	if(l1 == l2):
		return True
	else:
		return False
		
while True:
	rc522.wait_for_tag() # Attente du tag
	(error, tag_type) = rc522.request()
	if not error: # Si tag lu:
		(error, uid) = rc522.anticoll()
		if not error:
			print(f"L\'ID de ce badge est {uid}.")
			checker = [0,0,0,0,0] # Récupérez l'UID et mettez-le dans le checker
			if(comparer_liste(uid, checker) == True):
				print('Bon badge')
			else:
				print('Mauvais badge')
