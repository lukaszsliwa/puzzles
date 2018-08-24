#include <cstdio>

using namespace std;

int n, i;
long long int m, x0, tab[1000002], R;

long long int modulo(long long int n, long long int m) {
	return n - m * (n / m);
}

int main() {
	scanf("%d", &n);
	for(i = 0; i <= n; ++i)
		scanf("%lld", &tab[i]);
	scanf("%lld%lld", &m, &x0);
	R = modulo(tab[n], m);
	for(i = n - 1; i >= 0; --i)
		R = modulo (R * x0 + tab[i], m);
	printf("%lld\n", modulo(R, m));
	return 0;
}
