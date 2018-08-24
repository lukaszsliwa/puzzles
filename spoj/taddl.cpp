#include <cstdio>
using namespace std;

const int MAX = 101;

int a[MAX], b[MAX], wynik[MAX];

inline int get(int tab[]) {
	int len = 0;
	char znak;
	while((znak = getchar_unlocked()) 
		&& (znak < '0' || znak > '9'));
	tab[len++] = znak - '0';
	while((znak = getchar_unlocked())
		&& znak >= '0' && znak <= '9')
		tab[len++] = znak - '0';
	return len;
}

inline int pusty(int tab[], int s) {
	return s >= 0 ? tab[s] : 0;
}

int main() {
	int t, len_wynik, len_a, len_b, reszta;
	scanf("%d", &t);
	while(t--) {
		len_a = get(a); 
		len_b = get(b);
		reszta = len_wynik = 0;
		while(len_a > 0 || len_b > 0) {
			wynik[len_wynik] = pusty(a, len_a - 1) + pusty(b, len_b - 1) + reszta;
			reszta = 0;
			if(wynik[len_wynik] > 9) {
				wynik[len_wynik] %= 10;
				reszta = 1;
			}
			len_wynik++;
			len_a--; len_b--;
		}
		if(reszta) {
			wynik[len_wynik++] = 1;
		}
		for(int i = 0; i < len_wynik; ++i)
			putchar(wynik[len_wynik - i - 1] + '0');
		putchar('\n');
	}
}
