#include <vector>
#include <list>
#include <cstdio>
using namespace std;

const int n_max = 501;
int n, m, s[n_max];
bool graf[n_max][n_max], jest[n_max];

inline void wczytaj() {
	int a, b;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int y = 1; y <= m; ++y) {
			graf[i][y] = false;
			s[y] = -1;
		}
	while(scanf("%d%d", &a, &b) && a != 0)
		a > n ? graf[b][a - n] = true : graf[a][b - n] = true;
}

bool sciezka(int v) {
	for(int u = 1; u <= m; ++u)
		if(graf[v][u] && jest[u] == false) {
			jest[u] = true;
			if(s[u] < 0 || sciezka(s[u]))
				return s[u] = v;
		}
	return false;
}

main() {
	int wynik = 0;
	wczytaj();
	for(int i = 1; i <= n; ++i) {
		for(int y = 1; y <= m; ++y)
			jest[y] = false;
		if(sciezka(i))
			wynik++;
	}
	printf("%d\n", n + m - wynik);
}
