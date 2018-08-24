#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int N_MAX = 20002;
const int K_MAX = 22;
const int infty = 100000001;

struct krawedz {
	int v, waga;
	krawedz(int vv, int ww) : v(vv), waga(ww) { }
	bool operator <(const krawedz& K) const {
		return waga > K.waga;
	}
};

int n, k, s, dfs_f, droga[N_MAX], p[N_MAX];
int koszty[K_MAX][K_MAX], do_n[K_MAX], jest[N_MAX];
int R, wynik = infty;

vector< vector<krawedz> > graf;
vector< vector<int> > o, czas;
vector<int> r, tt;

priority_queue<krawedz> q;

typedef vector<krawedz>::iterator vec_iter;
typedef vector<int>::iterator vec_int;

void wczytaj() {
	int m, p, q, l, i, r, s, g;
	scanf("%d%d%d", &n, &m, &k);
	graf.resize(n + 1);
	o.resize(k + 2);
	czas.resize(k + 2);
	for(i = 0; i <= n; ++i)
		jest[i] = false;
	while(m--) {
		scanf("%d%d%d", &p, &q, &l);
		graf[p].push_back(krawedz(q, l));
		graf[q].push_back(krawedz(p, l));
	}
	scanf("%d", &g);
	while(g--) {
		scanf("%d%d", &r, &s);
		o[s].push_back(r);
	}
}

void odleglosci(int v) {
	vec_iter y;
	int i, u, w;
	for(i = 0; i <= n; ++i)
		droga[i] = infty;
	q.push(krawedz(v, 0));
	droga[v] = 0;
	while(!q.empty()) {
		v = q.top().v;
		w = q.top().waga;
		q.pop();
		for(y = graf[v].begin(); y < graf[v].end(); ++y) {
			u = y->v;
			if(droga[u] > droga[v] + y->waga) {
				droga[u] = droga[v] + y->waga;
				q.push(krawedz(u, droga[u]));
				p[u] = v;
			}
		}
	}
}

void oblicz_koszty() {
	int i, y;
	for(i = 1; i <= k + 1; ++i) {
		odleglosci(i);
		for(y = i + 1; y <= k + 1; ++y)
			koszty[i][y] = koszty[y][i] = droga[y];
	}
	odleglosci(n);
	for(i = 1; i <= k + 1; ++i)
		do_n[i] = droga[i];
}

bool sprawdz(int v) {
	int y;	
	for(y = 0; y < o[v].size(); ++y)
		if(!jest[o[v][y]])
			return false;
	return true;
}

void vec_print(vector<int>& g) {
	for(vector<int>::iterator y = g.begin();
	y != g.end(); ++y)
		printf("%d ", *y);
}

void podroz(int v, int koszt, int W) {
	jest[v] = true;
	//r.push_back(v);
	if(W == k + 1) {
		wynik = min(koszt + do_n[v], wynik);
		/*vec_print(r);
		printf("[%d]\n", koszt + do_n[v]);*/
	} else {
		for(int y = 2; y <= k + 1; ++y)
			if(v != y && !jest[y] && 
			koszt + koszty[v][y] < wynik && sprawdz(y))
				podroz(y, koszt + koszty[v][y], W + 1);
	}
	//r.pop_back();
	jest[v] = false;
}

main() {
	int i, y, x;
	wczytaj();
	oblicz_koszty();
	if(k == 0) {
		odleglosci(1);
		printf("%d\n", droga[n]);
		return 0;
	}
	for(i = 1; i <= k + 1; ++i)
		jest[i] = false;
	r.push_back(1);
	jest[1] = true;
	for(i = 2; i <= k + 1; ++i)
		if(koszty[1][i] < wynik && sprawdz(i))
			podroz(i, koszty[1][i], 2);
	printf("%d\n", wynik);
}
