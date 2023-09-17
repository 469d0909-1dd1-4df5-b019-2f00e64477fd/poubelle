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

a = lecture("csv/ex5.csv", ";", 0)
b = lecture("csv/ex5.csv", ";", 1)
c = lecture("csv/ex5.csv", ";", 2)
d = lecture("csv/ex5.csv", ";", 3)
e = lecture("csv/ex5.csv", ";", 4)
f = lecture("csv/ex5.csv", ";", 5)
g = lecture("csv/ex5.csv", ";", 6)

plt.figure(figsize=(8,4))
for i in range(len(col0)): # Vous pouvez changer les valeurs ici
	for i in range(len(col1)):
		plt.plot(col1[i], col1[i], label="Sortie")
		plt.title("Colonne 1")
		plt.grid()

plt.show()
