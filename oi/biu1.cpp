#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 100009;

int n, wynik[N_MAX];

struct zakres {
	int x, y, nr;
	zakres() { x = y = nr = 0; }
	zakres(int xx, int yy, int nn) : x(xx), y(yy), nr(nn) { }
};

struct Union {
	int p[N_MAX], rank[N_MAX];
	void make_set(int x) {
		p[x] = x;
		rank[x] = 0;
	}
	void link(int x, int y) {
		p[y] = x;
	}
	int find_set(int x) {
		return p[x];
	}
	void split(int x, int y) {
		link(find_set(x), find_set(y));
	}
} u;

vector<int> w;
vector< vector<int> > graf;
vector<zakres> biu; 

void wczytaj() {
	int a, b, m;
	scanf("%d%d", &n, &m);
	graf.resize(n + 3);
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	/*for(int i = 1; i <= n; ++i) {
		printf("[%d] ", i);
		for(vector<int>::iterator y = graf[i].begin(); y < graf[i].end(); ++y)
			printf("%d ", *y);
			printf("\n");
	}*/
}

void utworz_zbiory() {
	int i, y, zakres_od, u;
	for(i = 1; i <= n; ++i) {
		zakres_od = 0;
		sort(graf[i].begin(), graf[i].end());
		for(y = 0; y < graf[i].size(); ++y) {
			u = graf[i][y];
			if(u - zakres_od != 1)
				biu.push_back(zakres(zakres_od + 1, u - 1, i));
			zakres_od = u;
		}
		if(n != zakres_od || zakres_od == 0)
			biu.push_back(zakres(zakres_od + 1, n, i));
	}
}

bool f(const zakres& A, const zakres& B) {
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

int zakresy() {
	int i, y, l = 0;
	sort(biu.begin(), biu.end(), f);
	for(y = 0; y < biu.size(); ++y)
		u.make_set(biu[y].nr);
	//printf("[%d ; %d](%d)\n", biu.begin()->x, biu.begin()->y, biu.begin()->nr);
	for(y = 1; y != biu.size(); ++y) {
		if(biu[y - 1].y >= biu[y].x) {
			u.split(biu[y - 1].nr, biu[y].nr);
			biu[y].x = min(biu[y].x, biu[y - 1].x);
			biu[y].y = max(biu[y].y, biu[y - 1].y);
		}
		//printf("[%d ; %d](%d)\n", biu[y].x, biu[y].y, biu[y].nr);
	}
	for(i = 1; i <= n; ++i)
		wynik[u.p[i]]++;
	for(i = 1; i <= n; ++i)
		if(wynik[i] != 0) {
			l++;
			w.push_back(wynik[i]);
		}
	sort(w.begin(), w.end());
	return l;
}

main() {
	int i, y, R = 0;
	wczytaj();
	utworz_zbiory();
	printf("%d\n", zakresy());
	for(y = 0; y < w.size(); ++y)
		printf("%d ", w[y]);
}
