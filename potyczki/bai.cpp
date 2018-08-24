#include <vector>
#include <list>
using namespace std;

const int n_max = 5001;

int n;
bool zagrozony[n_max], jest[n_max];

vector<list<int> > graf;

inline void wczytaj() {
	int m, a, b;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
	}
	for(int i = 0; i <= n; ++i) {
		zagrozony[i] = false;
	}
}

int time_s = 1;

void dfs(int v) {
	for(list<int>::iterator y = graf[v].begin();
		y != graf[v].end(); ++y)
		if(jest[*y] == false) {
			jest[*y] = true;
			dfs(*y);
		}
}

main() {
	int wynik = 0;
	wczytaj();
	zagrozony[1] = true;
	for(int i = 2; i <= n; ++i) {
		for(int y = 2; y <= n; ++y)
			jest[y] = false;
		jest[i] = true;
		dfs(1);
		for(int y = 2; y <= n && zagrozony[i] == false; ++y)
			if(jest[y] == false)
				zagrozony[i] = true;
	}
	for(int i = 1; i <= n; ++i)
		if(zagrozony[i] == true) wynik++;
	printf("%d\n", wynik);
	for(int i = 1; i <= n; ++i)
		if(zagrozony[i] == true)
			printf("%d ", i);
}
