#include <stdio.h>

const int n_max = 50005;
int zap_t[n_max], primes[n_max], jump[n_max], p_len = 0;
bool prime_numbers[n_max];

int max(int& x, int& y) {
	return x < y ? y : x;
}

int min(int& x, int& y) {
	return x < y ? x : y;
}

void prime() {
	int i, j, pr = 0, e = n_max - 5;
	for(i = 2; i <= e; ++i)
		prime_numbers[i] = true;
	for(i = 2; i * i <= e; ++i)
		if(prime_numbers[i]) {
			primes[p_len++] = i;
			for(j = 2 * i; j <= e; j += i)
				prime_numbers[j] = false;
		}
	for(i = e; i >= 0; --i) {
		jump[i] = pr;
		if(prime_numbers[i])
			pr = i;
	}
}

int zap(int i) {
	int j, r;
	if(zap_t[i] != 0)
		return zap_t[i];
	for(r = 0, j = 2; j <= i; ++j)
		r += (zap_t[i / j] = zap(i / j));
	return (zap_t[i] = i * i - r);
}

int gcd(int a, int b) {
	int t = a % b, x = a, y = b;
	while(t != 0) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int zap2(int x, int y) {
	int i, j, k, r = (y - x) * x;
	for(i = x + 1; i <= y; ++i)
		if(!prime_numbers[i])
			for(j = 2; j <= x; ++j)
				if(gcd(i, j) != 1)
					r--;
	return r;
}

int main() {
	int a, b, c, t;
	scanf("%d", &t);
	zap_t[1] = 1;
	prime();
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		a /= c; b /= c;
		printf("%d\n", zap(min(a, b)) + zap2(min(a, b), max(a, b)));
	}
	return 0;
}
