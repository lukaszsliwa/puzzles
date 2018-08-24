t = input()
for x in range(t):
	linia = raw_input()
	liczba = map(int, linia.split())
	if liczba[0] % liczba[1] == 0:
		print 'TAK'
	else:
		print 'NIE'
