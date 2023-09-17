from numpy import pi

rayon = float(input('Rayon ?'))
hauteur = float(input('Hauteur ?'))

volume = ((1/3)*pi * (rayon**2) * hauteur)

print(f'Le volume du cone droit est {volume}.')
