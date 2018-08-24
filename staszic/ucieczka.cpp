#include <algorithm>
#include <cstdio>
#include <vector>
#include <list>
#include <queue>
using namespace std;

const int n_max = 100001;
const int infty = 10000000;

class kra {
public:
	int v, waga;
	kra(int vv, int ww = 0) : v(vv), waga(ww) {}
	bool operator < (const kra& K) const {
		return waga > K.waga;
	}
	kra& operator = (const kra& K) {
		v = K.v;
		waga = K.waga;
		return *this;
	}
};

int n, droga[n_max], koszt[n_max];
bool jest[n_max], wynik[n_max];

vector<list<kra> > graf;

typedef list<kra>::iterator list_iter;

int getint() {
	int t;
	char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) && znak >= '0' && znak <= '9')
		t = 10 * t + znak - '0';
	return t;
}

void wczytaj() {
	int a, b, c, m, i;
	n = getint(); m = getint();
	graf.resize(n + 1);
	while(m--) {
		a = getint(); b = getint(); c = getint();
		if(a != b) {
			graf[a].push_back(kra(b, c));
			graf[b].push_back(kra(a, c));
		}
	}
	for(i = 1; i <= n; ++i) {
		koszt[i] = infty;
		wynik[i] = false;
	}
}

int dijkstra(int s) {
	int l, droga_r[n_max];
	list_iter y;
	vector<kra> q;
	koszt[s] = 0;
	q.push_back(kra(s));
	while(!q.empty()) {
		kra v = q[0];
		pop_heap(q.begin(), q.end());
		q.pop_back();
		for(y = graf[v.v].begin(); y != graf[v.v].end(); ++y) {
			int u = y->v;
			if(koszt[u] > koszt[v.v] + y->waga) {
				koszt[u] = koszt[v.v] + y->waga;
				q.push_back(kra(u, koszt[u]));
				push_heap(q.begin(), q.end());
				droga[u] = v.v;
			}
		}
	}
	for(s = n; s != 0; s = droga[s])
		wynik[s] = true;
	return l;
}

void bfs(int v) {
	queue<int> q;
	wynik[v] = true;
	q.push(v);
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(list_iter y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(wynik[y->v] == false &&
				koszt[v] == y->waga + koszt[y->v]) {
				wynik[y->v] = true;
				q.push(y->v);
			}
	}
}

main() {
	int i, v, l;
	wczytaj();
	l = dijkstra(1);
	for(i = n; i != 0; i = droga[i])
			bfs(i);
	for(i = 1; i <= n; ++i)
		if(wynik[i])
			printf("%d\n", i);
}
