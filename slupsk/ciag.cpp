#include <stdio.h>

const int N_MAX = 1000001;
long long int tab[N_MAX];

long long int max(long long int, long long int);

long long int licz(int index, int index_n) {
	long long int l = 0, p = 0, t;
	while(index <= index_n) {
		t = l;
		l = p;
		p = t + tab[index++];
		p = max(p, l);
	}
	return max(p, l);
}

long long int max(long long int a, long long int b) {
	return a > b ? a : b;
}

int main() {
	long long int n, i, p;
	scanf("%lld", &n);
	for(i = 1; i <= n; ++i)
		scanf("%lld", &tab[i]);
	printf("%lld", max(licz(1, n - 1), licz(2, n)));
	return 0;
}
