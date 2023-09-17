liste = [1,2,3,4,5,6,7,8,9,10]
for_boucle = []
while_boucle = []

for x in liste:
	if(x%2==0):
		for_boucle.append(x)

i=0
while(i<len(liste)):
	if(liste[i]%2==0):
		while_boucle.append(liste[i])
	i=i+1

print(f'Pairs:\nBoucle for: {for_boucle}\nBoucle while: {while_boucle}')
