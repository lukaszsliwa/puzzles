#include <algorithm>
#include <cstdio>
using namespace std;

const int n_max = 100001;
long long int n, suma, tab[n_max];

main() {
	scanf("%lld", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &tab[i]);
		suma += tab[i];
	}
	sort(tab, tab + n);
	for(int i = 0, y = n - 1; i < y; ++i, --y)
		suma += (tab[y] - tab[i]);
	printf("%lld\n", suma);
}
