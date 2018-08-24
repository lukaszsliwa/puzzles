#include <stdio.h>

const int mod = 123456789;
const int z_max = 27;
const int n_max = 3000001;

long long int tab[n_max][z_max];
bool lubi[z_max][z_max];

int litera_int() {
	char znak;
	while((znak = getchar_unlocked()) 
		&& (znak < 'a' || znak > 'z'));
	return znak - 'a' + 1;
}

main() {
	int n, k, i, x, y;
	long long int suma = 0;
	scanf("%d%d", &n, &k);
	while(k--)
		lubi[litera_int()][litera_int()] = true;
	for(i = 1; i < z_max; ++i)
		tab[1][i] = 1;
	for(i = 2; i <= n; ++i)
		for(y = 1; y < z_max; ++y)
			for(x = 1; x < z_max; ++x) {
				if(lubi[x][y] == false)
					tab[i][y] += tab[i - 1][x];
				tab[i][y] %= mod;
			}
	for(i = 1; i < z_max; ++i)
		suma += tab[y][i];
	printf("%lld\n", suma % mod);
}
