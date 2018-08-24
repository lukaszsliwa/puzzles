#include <stdio.h>

const int N_MAX = 50005;
int tab[N_MAX], ile[N_MAX];

int abs(int e) {
	return e < 0 ? -e : e;
}

int oblicz(int R, int a, int b) {
	R -= (ile[a - 1] + ile[a]);
	R -= (ile[b - 1] + ile[b]);
	R += abs(tab[a] - tab[a + 1]);
	R += abs(tab[b] - tab[b + 1]);
	return R;
}

main() {
	int i, y, n, r = 0;
	scanf("%d%d", &n, &tab[i]);
	for(i = 2; i <= n; ++i) {
		scanf("%d", &tab[i]);
		ile[i - 1] = abs(tab[i - 1] - tab[i]);
		r += ile[i - 1];
	}
	tab[0] = tab[n + 1] = 0;
	for(i = 1; i <= n; ++i)
		for(y = 1; y <= n; ++y) {
			printf("zamiana %d z %d | %d na %d = %d\n", i, y, tab[i], tab[y], oblicz(r, i, y));
		}
}
