#include <cstdio>
#include <algorithm>
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

int n, k, droga[N_MAX], w = 0;
int koszty[K_MAX][K_MAX], do_n[K_MAX], jest[N_MAX];
int wynik = infty;

int tab[K_MAX][K_MAX][K_MAX + 1];

vector< vector<krawedz> > graf;
vector< vector<int> > o;

priority_queue<krawedz> q;

typedef vector<krawedz>::iterator vec_iter;
typedef vector<int>::iterator vec_int;

void wczytaj() {
	int m, p, q, l, i, r, s, g;
	scanf("%d%d%d", &n, &m, &k);
	graf.resize(n + 1);
	o.resize(k + 2);
	for(i = 0; i <= n; ++i)
		jest[i] = false;
	while(m--) {
		scanf("%d%d%d", &p, &q, &l);
		graf[p - 1].push_back(krawedz(q - 1, l));
		graf[q - 1].push_back(krawedz(p - 1, l));
	}
	scanf("%d", &g);
	while(g--) {
		scanf("%d%d", &r, &s);
		o[s - 1].push_back(r - 1);
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
			}
		}
	}
}

void oblicz_koszty() {
	int i, y;
	for(i = 0; i <= k; ++i) {
		odleglosci(i);
		koszty[i][i] = 0;
		for(y = i + 1; y <= k; ++y)
			koszty[i][y] = koszty[y][i] = droga[y];
	}
	odleglosci(n - 1);
	for(i = 0; i <= k; ++i)
		do_n[i] = droga[i];
}

bool sprawdz(int v) {
	int i;
	for(i = 0; i < o[v].size(); ++i)
		if(jest[v] < jest[o[v][i]])
			return false;
	return true;
}

/*int podroz2(int start, int t[]) {
	int i, j, x, mincost = infty, ccost, temp[K_MAX], mintour[K_MAX];
	if(start == k)
		return do_n[t[k]];
	
	for(i = start + 1; i <= k; ++i) {
		for(j = 0; j <= k; ++j) {
			temp[j] = t[j];
			jest[t[j]] = j;
		}
		temp[start + 1] = t[i];
		temp[i] = t[start + 1];
		if(sprawdz(t[start]) && koszty[t[start]][t[i]] + (ccost = podroz2(start + 1, temp)) < mincost) {
			mincost = koszty[t[start]][t[i]] + ccost;
			for(x = 0; x <= k; ++x)
				mintour[x] = temp[x];
		}
	}
	for(i = 0; i <= k; ++i)
		t[i] = mintour[i];
	return mincost;
}*/

void podroz(int v, int koszt, int ile) {
	jest[v] = true;
	printf("%d ", v + 1);
	if(ile == k)
		wynik = min(wynik, koszt + do_n[v]);
	for(int i = 1; i <= k && ile != k; ++i) {
		int u = i;
		if(v != y && !jest[u] && koszt + koszty[v][u] < wynik && sprawdz(u))
			podroz(u, koszt + koszty[v][u], ile + 1);
	}
	printf("\n");
	jest[v] = false;
}

main() {
	int i, y, x, trasa[K_MAX];
	wczytaj();
	oblicz_koszty();
	if(k == 0) {
		odleglosci(0);
		printf("%d\n", droga[n - 1]);
		return 0;
	}
	/*for(i = 0; i <= k; ++i) {
		trasa[i] = i;
		//printf("%d->%d %d\n", i, n - 1, do_n[i]);
	}*/
	for(i = 0; i <= k; ++i)
		jest[i] = false;
	for(i = 1; i <= k; ++i)
		if(koszty[0][i] < wynik)
			podroz(i, koszty[0][i], 0);
	printf("%d\n", wynik);
	//printf("%d\n", podroz2(0, trasa));
	/*printf("trasa: ");
	for(i = 0; i <= k; ++i)
		printf("%d ", trasa[i] + 1);
		printf("\n");*/
}
