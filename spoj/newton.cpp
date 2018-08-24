#include <cstdio>
using namespace std;

inline void input(int& v) {
	char znak;
	while((znak = getchar_unlocked()) &&
		(znak < '0' || znak > '9'));
	v = znak - '0';
	while((znak = getchar_unlocked()) &&
		znak >= '0' && znak <= '9')
		v = v * 10 + znak - '0';
}

int tab[1001][1001];

inline void binoms(int n) {
	for(int i = 0; i < n; ++i) {
		tab[i][0] = tab[i][i] = 1;
		for(int y = 1; y < i; ++y) {
			tab[i][y] = tab[i - 1][y - 1] + tab[i - 1][y];
			if(tab[i][y] > 1000000000)
				tab[i][y] = 0;
		}
	}
}

int main() {
	int t, n, k;
	binoms(1001);
	input(t);
	while(t--) {
		input(n); input(k);
		if(n < k) printf("0\n");
		else
		printf("%d\n", tab[n][k] != 0 ? tab[n][k] : -1);
	}

}
