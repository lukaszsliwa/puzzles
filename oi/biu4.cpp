#include <cstdio>
#include <stack>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

const int N_MAX = 100001;
int n, biurowiec = 0;

struct zakres {
	int v, od_u, do_u;
	zakres(int vv, int ou, int du) {
		v = vv;
		od_u = ou;
		do_u = du;
	}
};

vector< priority_queue<int, vector<int>, greater<int> > > graf;
vector< vector<int> > g;
vector<zakres> z;

void readvalue(int& e) {
	char znak;
	e = 0;
	while((znak = getchar()) 
		&& znak != ' ' && znak != '\n')
		e = e * 10 + (znak - '0');
}

void wczytaj() {
	int a, b, m;
	readvalue(n); readvalue(m);
	graf.resize(n + 1);
	g.resize(n + 1);
	while(m--) {
		readvalue(a); readvalue(b);
		graf[a].push(b);
		graf[b].push(a);
	}
}

void zbiory() {
	int i, u, od_wierzcholka, do_wierzcholka;
	for(i = 1; i <= n; ++i) {
		od_wierzcholka = 0;
		while(!graf[i].empty()) {
			u = graf[i].top();
			if(u - 1 == od_wierzcholka + 1 && u - 1 == i);
			else {
				if(od_wierzcholka + 1 == u - 1 && u - 1 != i) {
					g[i].push_back(u - 1);
					g[u - 1].push_back(i);
				} else if(u - od_wierzcholka != 1)
					z.push_back(zakres(i, od_wierzcholka + 1, u - 1));
			}
			graf[i].pop();
			od_wierzcholka = u;
		}
		if(n != od_wierzcholka && od_wierzcholka + 1 != n)
			z.push_back(zakres(i, od_wierzcholka + 1, n));
	}
	/*int y;
	for(i = 1; i <= n; ++i) {
		printf("%d: ", i);
		for(y = 0; y < g[i].size(); ++y) {
			printf("%d ", g[i][y]);
		}
		printf("\n");
	}*/
}

bool f(const zakres& A, const zakres& B) {
	return A.od_u < B.od_u || (A.od_u == B.od_u && A.do_u < B.do_u);
}

void redukcja_zbiorow() {
	int i, y, v, a, b;
	sort(z.begin(), z.end(), f);
	v = z[0].v;
	a = z[0].od_u;
	b = z[0].do_u;
	for(i = 1; i < z.size(); ++i) {
		if(b <= z[i].od_u) {
			z[i].od_u = min(a, z[i].od_u);
			z[i].do_u = max(b, z[i].do_u);
			g[v].push_back(z[i].v);
			g[z[i].v].push_back(v);
			v = min(v, z[i].v);
		} else {
			for(y = a; y <= b; ++y) {
				g[v].push_back(y);
				g[y].push_back(v);
			}
		}
		v = z[i].v;
		a = z[i].od_u;
		b = z[i].do_u;
	}
	for(y = a; y <= b; ++y) {
		g[v].push_back(y);
		g[y].push_back(v);
	}
	/*for(i = 0; i < z.size(); ++i)
		printf("%d -> [%d ; %d]\n", z[i].v, z[i].od_u, z[i].do_u);*/
}

int ile[N_MAX], jest[N_MAX], biu[N_MAX];

void dfs(int v) {
	int i;
	stack<int> S;
	S.push(v);
	jest[v] = true;
	biu[v] = ++biurowiec;
	while(!S.empty()) {
		v = S.top();
		S.pop();
		for(i = 0; i < g[v].size(); ++i)
			if(!jest[g[v][i]]) {
				S.push(g[v][i]);
				biu[g[v][i]] = biu[v];
				jest[g[v][i]] = true;
			}
	}
}

#define text(E) printf("%s\n", E);

main() {
	int i;
	wczytaj();
	zbiory();
	if(!z.empty())
		redukcja_zbiorow();
	for(i = 1; i <= n; ++i)
		biu[i] = i;
	for(i = 1; i <= n; ++i)
		if(!jest[i])
			dfs(i);
	for(i = 1; i <= n; ++i)
		ile[biu[i]]++;
	int r = 0;
	vector<int> wynik;
	for(i = 0; i <= n; ++i)
		if(ile[i] != 0) {
			r++;
			wynik.push_back(ile[i]);
		}
	sort(wynik.begin(), wynik.end());
	printf("%d\n", r);
	for(i = 0; i < wynik.size(); ++i)
		printf("%d ", wynik[i]);
		printf("\n");
}
