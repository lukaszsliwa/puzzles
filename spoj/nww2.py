import string

def nwd(a, b):
	while b:
		a, b = b, a % b
	return a

def nww(a, b):
	return (a * b) / nwd(a, b)

def main():
	t = input()
	for x in range(1, t + 1):
		n = input()
		liczba = raw_input()
		l = map(int, liczba.split()) 
		R = int(l[0])
		for i in range(1, len(l)):
			R = nww(R, int(l[i]))
		print R

main()
