#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N_MAX = 100001;

int n;
bool jest[N_MAX];

struct zakres {
	int x, y;
	zakres() { x = y = -1; }
	zakres(int xx, int yy) : x(xx), y(yy) { }
};

vector<int> wynik, stack;
vector< set<int> > graf;
vector< vector<zakres> > biu; 

void wczytaj() {
	int a, b, m;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].insert(b);
		graf[b].insert(a);
	}
}

void wypisz() {
	int i;
	for(i = 1; i <= n; ++i) {
		printf("[ %d ] ", i);
		for(vector<zakres>::iterator y = biu[i].begin();
			y != biu[i].end(); ++y)
			printf("[%d ; %d] ", y->x, y->y);
		printf("\n");
	}
}

void nowy_graf() {
	int i, zakres_od;
	biu.resize(n + 1);
	for(i = 1; i <= n; ++i) {
		zakres_od = 0;
		for(set<int>::iterator y = graf[i].begin();
			y != graf[i].end(); ++y) {
			if(*y - zakres_od != 1)
				biu[i].push_back(zakres(zakres_od + 1, *y - 1));
			zakres_od = *y;
		}
		if(n != zakres_od)
			biu[i].push_back(zakres(zakres_od + 1, n));
	}
}

bool dfs(int v) {
	int i, u, q, l = 0;
	stack.push_back(v);
	jest[v] = true;
	while(!stack.empty()) {
		v = stack.back();
		stack.pop_back();
		l++;
		for(vector<zakres>::iterator y = biu[v].begin();
			y != biu[v].end(); ++y) {
			for(q = y->x; q <= y->y; ++q)
				if(q != v && !jest[q]) {
					jest[q] = true;
					stack.push_back(q);
				}
		}
	}
	wynik.push_back(l);
	return true;
}

main() {
	int i, R = 0;
	wczytaj();
	nowy_graf();
	for(i = 1; i <= n; ++i)
		if(!jest[i])
			R += dfs(i);
	sort(wynik.begin(), wynik.end());
	printf("%d\n", R);
	for(vector<int>::const_iterator y = wynik.begin();
		y != wynik.end(); ++y)
		printf("%d ", *y);
	printf("\n");
	wypisz();
}
