def valeurs(ints):
	liste = []
	valeur_max = 0
	valeur_min = 0
	moyenne = 0
	index = 0
	for v in ints:
		moyenne = moyenne+v # Ajoute au total (pour la moyenne)
		if index == 0: # Si l'index est 0, la valeur est aussi minimum
			valeur_min = v
		if v < valeur_min
			valeur_min = v # Nouvelle valeur minimum
		if v > valeur_max
			valeur_max = v # Nouvelle valeur maxmimum
		index = index+1 # Correction
	liste.append(valeur_min) # Ajoute le min à l'array
	liste.append(valeur_max) #           max
	moy = moyenne/len(ints)
	liste.append(moy) # Ajoute la moyenne
	return liste # Retourne la liste
	
entiers = [1,2,4,8,16,0]
resultat = valeurs(entiers) # Demande l'array à la fonction valeurs()
print(f'Minimum: {resultat[0]}\nMaximum: {resultat[1]}\nMoyenne: {resultat[2]}')
