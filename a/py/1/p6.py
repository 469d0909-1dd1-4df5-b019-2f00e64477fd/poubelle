n1 = int(input('Nombre 1: '))
n2 = int(input('Nombre 2: '))
n3 = int(input('Nombre 3: '))

array = ([n1, n2, n3])

if n1 == n2 == n3:
	print('Les trois nombres sont identiques.')

if n1 > n2:
	if n2 > n3:
		print(f'{n1} est supérieur.') # Cas 1
	else:
		print(f'{n3} est supérieur.') # Cas 2
else:
	if n2 > n3:
		print(f'{n2} est supérieur.') # Cas 3
	else:
		print(f'{n3} est supérieur.') # Cas 4
