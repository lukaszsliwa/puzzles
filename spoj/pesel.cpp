#include <stdio.h>

int main() {
	int t, suma, tab[12];
	long long int pesel;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &pesel);
		int cyfra, p = 11;
		while(pesel > 0) {
			cyfra = pesel % 10;
			tab[p--] = cyfra;
			pesel = (pesel - cyfra) / 10;
		}
		suma = 1 * tab[1] + 3 * tab[2] + 7 * tab[3] + 9 * tab[4] + 1 * tab[5] + 3 * tab[6] + 7 * tab[7] + 9 * tab[8] + 1 * tab[9] + 3 * tab[10] + 1 * tab[11];
		printf(suma % 10 == 0 ? "D\n" : "N\n");
	}
}
