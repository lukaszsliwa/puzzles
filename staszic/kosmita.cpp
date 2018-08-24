#include <stdio.h>

const int N_MAX = 3003;
const int infty = 1000000000;
int n, s, p, a, b, c, d, e, droga[N_MAX];

void wczytaj() {
	int i;
	scanf("%d%d%d%d%d%d%d%d", &n, &s, &p, &a, &b, &c, &d, &e);
	for(i = 1; i <= n; ++i)
		droga[i] = infty;
}

#define dlugosc(x, y)\
	(a * y * y + b * y + c * x * x + d * x + e) % p


void bellman_ford(int S) {
	int u, v, t;
	droga[S] = 0;
	for(u = 1; u <= n; ++u)
		for(v = 1; v <= n; ++v)
			if(droga[v] > droga[u] + dlugosc(u, v))
				droga[v] = droga[u] + dlugosc(u, v);
	for(u = 1; u <= n; ++u)
		for(v = 1; v <= n; ++v)
			if(droga[v] > droga[u] + dlugosc(u, v))
				droga[v]  = droga[u] + dlugosc(u, v);
}

main() {
	int waga, i;
	wczytaj();
	droga[s] = 0;
	for(i = 1; i <= n; ++i)
		if(i != s)
			droga[i] = dlugosc(s, i);
	bellman_ford(s);
	for(i = 1; i <= n; ++i)
		printf("%d\n", droga[i]);
}
