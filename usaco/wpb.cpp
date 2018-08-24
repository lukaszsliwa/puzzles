#include <stdio.h>
#include <math.h>

int d;
long long n, tab[100000001];
bool pierwsza[100000001];

void pierwsze(long long int& p) {
	int i, l;
	for(i = 1; i <= p; ++i)
		pierwsza[i] = true;
	pierwsza[1] = false;
	for(i = 2; i * i <= p; ++i) {
		l = i * 2;
		while(pierwsza[i] && l <= p) {
			pierwsza[l] = false;
			l += i;
		}
	}
	l = -1;
	for(i = p; i >= 1; --i) {
		tab[i] = l;
		if(pierwsza[i])
			l = i;
	}
}

main() {
	int cyfr = 0, w = 0, p;
	bool stop = true;
	scanf("%d%lld", &d, &n);
	pierwsze(n);
	cyfr = 1;
	p = n;
	while(p >= d && stop) {
		cyfr *= 10;
		w = n % cyfr;
		printf("tab[%d] = %d\n", w, tab[w]);
		if((int)log10(tab[w]) == (int)log10(w)) {
			p = (n - w) / cyfr;
			printf("%d%ld\n", p, tab[w]);
			stop = false;
		}
		p = (p - p % 10) / 10;
	}
}
