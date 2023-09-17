from numpy import sqrt

nombre = int(input('Nombre réel? '))

if nombre >= 0:
	racine = sqrt(nombre)
	print(f'La racine de {nombre} est {racine}.')
else:
	print('Nombre non valide.')
