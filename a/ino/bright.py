import serial, time, csv

ser = serial.Serial('COM6', 9600)
ser.flushInput()

def collect():
    ser.reset_input_buffer()
    data = ser.readline()
    data2 = data.decode('utf-8')
    print(f'{data2}')
    

while True:
    collect()
    time.sleep(0.5)
