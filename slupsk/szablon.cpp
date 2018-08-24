#include <cstdio>

using namespace std;

const int N_MAX = 500001;
int n, pi[N_MAX], sz[N_MAX], zakres[N_MAX];
char tab[N_MAX];

int input() {
	int q = 1;
	char znak;
	while(scanf("%c", &znak) && znak != '\n')
		tab[q++] = znak;
	return q;
}

void prefix_function() {
	int q, k = 0;
	pi[1] = 0;
	for(q = 2; q < n; ++q) {
		k = pi[q - 1];
		while(k > 0 && tab[q] == tab[k + 1])
			k = pi[k];
		if(tab[q] == tab[k + 1])
			k++;
		pi[q] = k;
	}
}

void drukuj() {
	int i;
	for(i = 1; i < n; ++i)
		printf("[%d] ", sz[i]);
		printf("\n");
	for(i = 1; i < n; ++i)
		printf("[%d] ", zakres[i]);
		printf("\n\n");
}

int main() {
	int i, s;
	n = input();
	prefix_function();
	for(i = 1; i < n; ++i)
		sz[i] = zakres[i] = i;
	for(i = 1; i < n; ++i) {
		s = sz[pi[i]];
		if(pi[i] > 0 && zakres[s] >= i - s) {
			sz[i] = s;
			zakres[s] = i;
		}
		drukuj();
	}
	printf("%d", sz[n - 1]);
	return 0;
}
