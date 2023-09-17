a1 = ['35\r\n','30\r\n','61\r\n'] # Ajoutez autant de valeurs que vous voulez
type(a1)

# À la suite:

x = []
for elt in a1:
	x.append(int(elt))
	print(elt)
print('x=', x)

# À la suite:

plt.plot(x)

# À la suite:

a2 = ['35\r\n','30\r\n','61\r\n'] # Ajoutez autant de valeurs que vous voulez
type(a2) # tuple

a1 = ['35\r\n','30\r\n','61\r\n'] # Ajoutez autant de valeurs que vous voulez
a3 = str(a1)
z1 = a3.replace('"', '')
z2 = z1.replace('\\r', '')
z3 = z2.replace('\\n', '')
print(z3)
