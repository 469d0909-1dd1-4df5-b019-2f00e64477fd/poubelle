import network, time

sta_if = network.WLAN(network.STA_IF)
sta_if.active(True)
while True:
    scan = sta_if.scan()
    print(scan)
    time.sleep(1)
