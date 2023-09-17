import network, gc
from machine import Pin

ssid = "COVID19 Test Tower"
password = '91DIVOC'
station = network.WLAN(network.STA_IF)
station.active(True)
station.connect(ssid, password)
while station.isconnected() == False:
    pass

print('Connecté - Adresse IP:')
print(station.ifconfig()[0])

try:
    import usocket as socket
except:
    import socket

gc.collect() # Garbage collector

led = Pin(27, Pin.OUT)

etats = []
statut = 0

def web_page():
  if led.value() == 1:
    gpio_state="ON"
  else:
    gpio_state="OFF"
  
  tablecontents = ""
  for i in range(len(etats)):
      # 0: ID
      # 1: Statut
      # 2: 0/1
      tablecontents += f'<tr><td style="font-family: monospace;">{etats[i][0]}</td><td>{etats[i][1]}</td><td>{etats[i][2]}</td></tr>'
  
  html = """<html><head> <title>ESP Web Server</title> <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,"> <style>html{font-family: Helvetica; display:inline-block; margin: 0px auto; text-align: center;}
  h1{color: #0F3376; padding: 2vh;}p{font-size: 1.5rem;}.button{display: inline-block; background-color: #e7bd3b; border: none; 
  border-radius: 4px; color: white; padding: 16px 40px; text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}
  .button2{background-color: #4286f4;}</style></head><body> <h1>ESP Web Server</h1> 
  <p>LED state: <strong>""" + gpio_state + """</strong></p><p><a href="/?led=on"><button class="button">ON</button></a></p>
  <p><a href="/?led=off"><button class="button button2">OFF</button></a></p>
  <table><tr><td><b>ID</b></td><td><b>Statut</b></td><td><b>Valeur</b></td></tr>""" + tablecontents + """</table>
  </body></html>"""
  return html

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)

while True:
  conn, addr = s.accept()
  print('Got a connection from %s' % str(addr))
  request = conn.recv(1024)
  request = str(request)
  print('Content = %s' % request)
  led_on = request.find('/?led=on')
  led_off = request.find('/?led=off')
  statut = statut + 1
  if led_on == 6:
    print('LED ON')
    led.value(1)
    etats.append([statut, 'On', led.value()])
  if led_off == 6:
    print('LED OFF')
    led.value(0)
    etats.append([statut, 'Off', led.value()])
  response = web_page()
  conn.send('HTTP/1.1 200 OK\n')
  conn.send('Content-Type: text/html\n')
  conn.send('Connection: close\n\n')
  conn.sendall(response)
  conn.close()
