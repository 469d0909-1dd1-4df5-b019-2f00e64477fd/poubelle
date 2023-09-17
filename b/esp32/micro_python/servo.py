import machine
import time

p2 = machine.Pin(27)
pwm2 = machine.PWM(p2)
pwm2.freq(50)

pwm2.duty(90)
print(pwm2)
time.sleep(2)
pwm2.duty(1)
print(pwm2)

print(PWM)

#while True:
#    d = 1000
#    pwm2.duty(d)
#    tSleep = (d/1023)*20
#    time.sleep(tSleep)
#    print (pwm2)
#    time.sleep(2)
