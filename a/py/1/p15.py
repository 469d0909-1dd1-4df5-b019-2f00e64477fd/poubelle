liste = [0,1,2,3,4,5]
liste3 = [0,0,0,0,0,0]

x2 = []
for x in liste:
	x2.append(x**2)

i = 0
while(i < len(liste)):
	liste3[i] = liste[i]**2
	i=i+1

print(f'Valeurs initiales: {liste}')
print(f'Carré des valeurs (for): {x2}')
print(f'Carré des valeurs (while): {liste3}')
