import matplotlib.pyplot as plt
import numpy as np
%matplotlib inline

def lecture(fichier, sep, n):
	file = open(fichier, 'r')
	reader = csv.reader(file, delimiter=sep)
	col = []
	for row in reader:
		try:
			sep_decimal = row[n].replace(",", ".")
			col.append(float(sep_decimal))
		except:
			pass
	file.close()
	return col

a = lecture("csv/ex4.1.csv", ";", 1)
b = lecture("csv/ex4.2.csv", ";", 1)
c = lecture("csv/ex4.1.csv", ";", 0)

plt.figure(figsize=(8,4))
plt.plot(x,a,label="2x")
plt.plot(x,b,label="x")
plt.xlabel('exp(x)')
plt.legend()
plt.grid()
plt.show()
