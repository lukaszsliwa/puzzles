o_frac = 1
f = []
f[0] = 1
f[1] = 1

def frac(n):
	if n <= o_frac:
		return f[n]
	else:
		s = f[o_frac]
		for x in range(o_frac + 1, n):
			f[x] = frac[x - 1] * x
		o_frac = n
		return f[n]

def binoms(n, k):
	return frac(n) / (frac(k) * frac(n - k))

t = input()
for x in range(t):
	line = raw_input()
	var = map(int, line.split())
	print binoms(var[0], var[1])
