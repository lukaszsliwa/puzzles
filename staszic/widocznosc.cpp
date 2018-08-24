#include <stdio.h>

const int N_MAX = 500005;
long long int tab[N_MAX], w[N_MAX];

main() {
	long long int i, y, min, max, n;
	scanf("%lld", &n);
	for(i = 1; i <= n; ++i)
		scanf("%lld", &tab[i]);
	w[1] = -1;
	min = max = 1;
	for(i = 2; i <= n; ++i) {
		if(tab[i] < tab[min]) {
			w[i] = i - 1;
			min = i;
		} else if(tab[i] >= tab[max]) {
			w[i] = -1;
			max = i;
		} else {
			y = i - 1;
			while(tab[y] <= tab[i])
				y = w[y];
			w[i] = y;
		}
	}
	for(i = 1; i <= n; ++i)
		printf("%lld\n", w[i]);
}
