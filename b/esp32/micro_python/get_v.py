from machine import Pin, ADC
import time

v = ADC(Pin(36, Pin.IN))
led = Pin(27, Pin.OUT)

temps = 0

f = open('data.txt', 'w+')
f.write('Temps[s],Tension[V],Valeur[dec],Etat\n')

while True:
    temps = temps + 0.5
    value_read = v.read()
    value_volt = value_read * (3.3 / 4095)
    print(round(value_volt, 2), "V\t= ", value_read)
    f.write(f'{temps},{round(value_volt, 2)},{value_read},')
    if value_read >= 520:
        led.value(1)
        time.sleep(0.5)
        f.write('on\n')
    else:
        led.value(0)
        time.sleep(0.5)
        f.write('off\n')
