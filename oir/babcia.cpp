#include <cstdio>
#include <vector>

using namespace std;

const int N_MAX = 10;

int droga[N_MAX];
vector< vector<int> > graf;

void go(int v, int f) {
	droga[v] = f;
	for(vector<int>::iterator y = graf[v].begin();
		y != graf[v].end(); ++y)
		if(*y != f && droga[*y] != -1)
			go(*y, v);
}

main() {
	scanf("%d", &z);
	while(z--) {
		scanf("%d%d", &n, &m);
		for(i = 0; i <= n; ++i) {
			droga[i] = -1;
			jest[i] = false;
		}
		graf.resize(n + 1);
		while(m--) {
			scanf("%d%d", &a, &b);
			graf[a].push_back(b);
			graf[b].push_back(a);
		}
		go(0, -1);
		for(i = 0; i <= n; ++i)
			jest[i] = false;
		i = 0;
		jest[i] = true;
		while(droga[i] != 0) {
			jest[i] = true;
			i = droga[i];
		}
		bool stop = false
		for(i = 1; i <= n && !stop; ++i)
			if(!jest[i])
				stop = true;
		printf(stop ? "NIE\n" : "TAK\n");
		graf.clear();
	}
}
