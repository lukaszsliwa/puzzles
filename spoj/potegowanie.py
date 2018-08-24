import string

a = raw_input()
lista = string.split(a,' ')

for x in range(len(lista)):
	lista[x] = int(lista[x])

print lista[0]**lista[1]
