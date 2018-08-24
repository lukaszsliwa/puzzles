#include <cstdio>
using namespace std;

const int n_max = 2001;

class mpki {
	int n, skojarzony[n_max];
	bool graf[n_max][n_max], jest[n_max];

	int getint() {
		int t; char znak;
		while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
		for(t = znak - '0'; (znak = getchar_unlocked()) && 
			znak >= '0' && znak <= '9'; t = t * 10 + znak - '0');
		return t;
	}
public:
	mpki() {
		int k, tab[n_max];
		n = getint();
		for(int i = 1; i <= n; ++i) {
			k = getint();
			while(k--)
				tab[getint()] = i;
			for(int y = 1; y <= n; ++y)
				if(tab[y] != i)
					graf[i][y] = true;
			skojarzony[i] = -1;
		}
	}
	bool sciezka(int v) {
		for(int i = 1; i <= n; ++i)
			if(graf[v][i] && !jest[i]) {
				jest[i] = true;
				if(skojarzony[i] < 0 || sciezka(skojarzony[i]))
					return (skojarzony[i] = v);
			}
		return false;
	}
	int skojarzenie() {
		int wynik = 0;
		for(int i = 1; i <= n; ++i) {
			for(int y = 1; y <= n; ++y)
				jest[y] = false;
			if(sciezka(i))
				wynik++;
		}
		return wynik;
	}
	~mpki() {
		printf("%d\n", n - skojarzenie());
	}
};

main() {
	mpki m;
}
