#include <stdio.h>

const int N_MAX = 1000002;
int n, pi[N_MAX];
char tab[N_MAX];

void prefix_function() {
	int k = 0, q;
	pi[1] = 0;
	for(q = 2; q <= n; ++q) {
		while(k > 0 && tab[k + 1] != tab[q])
			k = pi[k];
		if(tab[k + 1] == tab[q])
			k++;
		pi[q] = k;
	}
}

void wczytaj() {
	int q;
	scanf("%d%s", &n, &tab[1]);
}

int digitslen(int e) {
	int len = 0;
	while(e > 0) {
		e /= 10;
		len++;
	}
	return len;
}

main() {
	int m, p, s, suma;
	scanf("%d", &m);
	while(m--) {
		wczytaj();
		prefix_function();
		p = n - pi[n];
		if(2*p > n || (n % p != 0))
			printf("-2\n");
		else {
			s = digitslen(n / p);
			printf("%d\n", n - (s + p + 1));
		}
	}
}
