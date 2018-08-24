#include <cstdio>
#include <algorithm>
using namespace std;

int tab[101];

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &tab[i]);
		while(n--)
			printf("%d ", tab[n]);
		printf("\n");
	}
}
