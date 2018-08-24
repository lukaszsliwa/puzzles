#include <cstdio>
using namespace std;

int main() {
	int n, k, *tab;
	scanf("%d%d", &n, &k);
	tab = new int[n + 1];
	k %= n;
	for(int i = 0; i < n; ++i)
		scanf("%d", &tab[i]);
	for(int i = k; i < n; ++i)
		printf("%d ", tab[i]);
	for(int i = 0; i < k; ++i)
		printf("%d ", tab[i]);
	delete []tab;
}
