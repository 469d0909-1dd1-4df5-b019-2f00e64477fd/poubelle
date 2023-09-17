import numpy as np
import matplotlib.pyplot as plt

def f(x):
	return x**2

valeur = -3
indice = 0

# Définition du graphique
X = np.linspace(-3,3,256,endpoint=True)
plt.figure()
plt.title('f(x) = x^2') # Titre
plt.xlabel('x') # Abscisses
plt.ylabel('y') # Ordonnées

# Valeurs
while(valeur < 4):
	resultat = f(X)
	plt.plot(X,resultat) # Trace la courbe
	indice = indice + 1
	valeur = valeur + 1

plt.grid() # Affiche la grille
plt.show() # Affiche le graph
