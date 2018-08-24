#include <stdio.h>

int t, l, tab[101];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &l);
		for(int i = 1; i <= l; ++i)
			scanf("%d", &tab[i]);
		for(int i = 2; i <= l; i += 2)
			printf("%d ", tab[i]);
		for(int i = 1; i <= l; i += 2)
			printf("%d ", tab[i]);
		printf("\n");
	}
}
