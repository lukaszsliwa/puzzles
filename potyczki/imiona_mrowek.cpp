#include <stdio.h>
#include <string.h>

int max(int a, int b) {
	return a < b ? b : a;
}

main() {
	int i, n, l = 0, len, wynik = 0;
	char tab[21];
	bool alfabet[28];
	scanf("%d", &n);
	while(n--) {
		scanf("%s", tab);
		len = strlen(tab);
		for(i = 0; i <= 27; ++i)
			alfabet[i] = false;
		for(i = 0; i < len; ++i)
			alfabet[tab[i] - 'a'] = true;
		for(l = 0, i = 0; i <= 27; ++i)
			if(alfabet[i])
				l++;
		wynik = max(wynik, l);
	}
	printf("%d\n", wynik);
}
