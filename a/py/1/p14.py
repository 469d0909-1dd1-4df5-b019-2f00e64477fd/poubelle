while True:
	try:
		char = int(input('Chaine de caractères? '))
		break
	except ValueError:
		print(f'Un nombre était attendu...')
