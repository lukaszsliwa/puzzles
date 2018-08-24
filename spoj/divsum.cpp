#include <stdio.h>

const int n_max = 500001;
int tab[n_max];

int getint() {
	int t;
	char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) && znak <= '9' && znak >= '0')
		t = t * 10 + znak - '0';
	return t;
}

main() {
	int i, t, w, n, q;
	t = getint();
	while(t--) {
		n = getint();
		if(tab[n] != 0)
			printf("%d\n", tab[n]);
		else {
			for(w = 1, i = 2; i * i <= n; ++i)
				if(n % i == 0) {
					w += i;
					if(n / i > i)
						w += (n / i);
				}
			if(n == 1)
				w = 0;
			tab[n] = w;
			printf("%d\n", w);
		}
	}
}
