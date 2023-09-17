# Include libs
import RPi.GPIO as GPIO
import time, datetime, picamera, os, smtplib
from email import encoders
from email.mime.base import MIMEBase
from email.mime.multipart import MIMEMultipart

# Start camera instance
camera = picamera.PiCamera()

# Get board ready
GPIO.setmode(GPIO.BCM)
GPIO.setup(23, GPIO.IN) # PIR pin
GPIO.setup(24, GPIO.OUT) # LED pin

# Space (for email content)
COMMASPACE = ", "

# Send email
def send(image):
	sender = 'sender@example.com' # SMTP Login Username
	password = 'sender\'s password'
	recipients = ['receiver@example.com']
	outer = MIMEMultipart()
	outer['Subject'] = 'Sujet'
	outer['To'] = COMMASPACE . join(recipients)
	outer['From'] = sender
	attachments = [image]
	for file in attachments:
		with open(file, 'rb') as fp:
			msg = MIMEBase('image', 'jpg')
			msg.set_payload(fp.read())
			
		encoders.encode_base64(msg)
		msg.add_header('Content - Disposition', 'attachment', filename=os.path.basename(file))
		outer.attach(msg)
		
	composed = outer.as_string()
	
	# Send the message
	try:
		with smtplib.SMTP('smtp.example.com', 587) as s:
			s.ehlo()
			s.starttls()
			s.ehlo()
			s.login(sender, password)
			s.sendmail(sender, recipients, composed)
			s.close()
			print("Sent mail!")
	except:
		print("An error occured: ", sys.exc_info()[0])
		raise

try:
	time.sleep(2) # Stabilise the sensor
	while True:
		ts = time.time()
		st = datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%dT%H:%M:%SZ') # ISO
		if GPIO.input(23):
			GPIO.output(24, True)
			time.sleep(0.5)
			print("I detected a movement at {}".format(st))
			camera.capture("image_{}".format(st))
			send(image) # Send the image
			time.sleep(2)
			GPIO.output(24, False)
			time.sleep(5)
		
		time.sleep(0.1)

except:
	GPIO.cleanup()
