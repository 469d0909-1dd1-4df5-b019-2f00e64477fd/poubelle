import numpy as np
import matplotlib.pyplot as plt

def f(x):
	return np.sinc(x/np.pi)

valeur = 0
indice = 0

# Définition du graphique
X = np.linspace(-1,21,256,endpoint=True)
plt.figure()
plt.title('f(x) = sin(x) / x') # Titre
plt.xlabel('x') # Abscisses
plt.ylabel('y') # Ordonnées

# Valeurs
while(valeur < 21):
	resultat = f(X)
	plt.plot(X,resultat) # Trace la courbe
	indice = indice + 1
	valeur = valeur + 1

plt.grid() # Affiche la grille
plt.show() # Affiche le graph
