import csv
array_x = []
array_exp_x = []
for i in range(21):
	array_x.append(i/10)
	array_exp_x.append(np.exp(i/10))

fichier = "csv/ex2.csv"
with open(fichier, 'w') as f:
	ecriture = csv.writer(f, delimiter = ';')
	ecriture.writerow(['x', 'exp(x)'])
	for i in range(21):
		ecriture.writerow([array_x[i], array_exp_x[i]])
