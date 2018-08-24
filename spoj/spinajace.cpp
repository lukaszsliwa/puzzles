#include <cstdio>
#include <queue>
using namespace std;

struct kra {
	int waga, v;
	kra(int ww, int vv) : waga(ww), v(vv) {}
	bool operator < (const kra& K) const {
		return waga > K.waga;
	}
};

const int infty = 100000000;

priority_queue<kra> q;

int main() {
	int r;
	scanf("%d", &r);
	while(r--) {
		int n, m, a, b, w;
		while(getchar() != '=');
		scanf("%d", &n);
		while(getchar() != '=');
		scanf("%d", &m);
		vector<kra> graf[n + 1];
		int klucz[n + 1];
		bool jest[n + 1];
		for(int i = 0 ; i <= n; ++i) {
			jest[i] = true;
			klucz[i] = infty;
		}
		char kraw[30];
		while(m--) {
			scanf("%s", kraw);
			for(int i = 0; i < strlen(kraw); ++i)
				if(kraw[i] < '0' || kraw[i] > '9')
					kraw[i] = ' ';
			sscanf(kraw, "%d %d %d", &a, &b, &w);
			graf[a].push_back(kra(w, b));
			graf[b].push_back(kra(w, a));
		}
		klucz[0] = 0;
		q.push(kra(0, 0));
		while(!q.empty()) {
			int u = q.top().v;
			q.pop();
			jest[u] = false;
			for(int i = 0 ; i < graf[u].size(); ++i) {
				int s = graf[u][i].v;
				if(jest[s] && graf[u][i].waga < klucz[s]) {
					klucz[s] = graf[u][i].waga;
					q.push(kra(klucz[s], s));
				}
			}
		}
		int suma = 0;
		for(int i = 0; i < n; ++i)
			suma += klucz[i];
		printf("%d\n", suma);
	}
}
