import csv
array_x = []
array_2x = []
array_x2 = []
for i in range(6):
	array_x.append(i)
	array_2x.append(2*i)
	array_x2.append(i**2)

fichier = "csv/ex1.csv"
with open(fichier, 'w') as f:
	ecriture = csv.writer(f, delimiter = ';')
	ecriture.writerow(['x', '2x', 'x^2'])
	for i in range(6):
		ecriture.writerow([array_x[i], array_2x[i], array_x2[i]])
