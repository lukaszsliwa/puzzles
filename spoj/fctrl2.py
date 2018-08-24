def silnia(a):
	if a == 1:
		return 1
	else:
		return a * silnia(a - 1)

m = input()
for i in range(1, m+1):
	n = input()
	print silnia(n)
