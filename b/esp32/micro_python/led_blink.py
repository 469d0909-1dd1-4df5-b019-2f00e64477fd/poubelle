from machine import Pin, Timer
import time

led = Pin(27, Pin.OUT)

timer = Timer(0)
toggle = 1

def blink(timer):
    global toggle
    if toggle == 1:
        led.value(0)
        toggle = 0
        print("led off")
    else:
        led.value(1)
        toggle = 1
        print("led on")

timer.init(freq=1, mode=Timer.PERIODIC, callback=blink)
