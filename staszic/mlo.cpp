#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

const int infty = 10000000;
const int n_max = 1001;

class mlo {
	
	class kra;

	int n, jest[n_max];
	bool wynik, ma_cykl[n_max];
	vector<list<kra> > graf;
	map<string, int> przedmiot;

	class kra {
	public:
		int v;
		long long int waga;
		kra(int vv, long long int ww) {
			v = vv;
			waga = ww;
		}
		bool operator < (const kra& K) const {
			return waga > K.waga;
		}
	};
public:
	mlo() : wynik(false) {
		int m, i;
		long long int c;
		string p, a, b;
		cin >> n >> m;
		graf.resize(n + 1);
		for(i = 1; i <= n; ++i) {
			cin >> p;
			przedmiot.insert(make_pair(p, i));
			jest[i] = ma_cykl[i] = 0;
		}
		while(m--) {
			cin >> a >> b >> c;
			graf[przedmiot[a]].push_back(kra(przedmiot[b], c));
		}
		for(i = 1; i <= n; ++i)
			if(jest[i] == 0)
				cykl(i);
		for(i = 1; i <= n && 
			(wynik = dijkstra(i)) == false; ++i);
	}
	~mlo() {
		puts(wynik ? "TAK" : "NIE");
	}
	void cykl(int v) {
		jest[v] = 1;
		for(list<kra>::iterator y = graf[v].begin();
			y != graf[v].end(); ++y)
			if(jest[y->v] == 0)
				cykl(y->v);
			else if(jest[y->v] == 1)
				ma_cykl[y->v] = true;
		jest[v] = 2;
	}
	bool dijkstra(int v) {
		if(ma_cykl[v] == false) 
			return false;
		int i, p = v, droga[n_max], u;
		vector<kra> q;
		q.push_back(kra(v, 0));
		for(i = 0; i <= n; ++i)
			droga[i] = infty;
		droga[v] = 0;
		while(!q.empty() && droga[p] == 0) {
			v = q[0].v;
			pop_heap(q.begin(), q.end());
			q.pop_back();
			list<kra>::iterator y;
			for(y = graf[v].begin(); y != graf[v].end(); ++y) {
				u = y->v;
				if(droga[u] > droga[v] + y->waga) {
					droga[u] = droga[v] + y->waga;
					q.push_back(kra(u, droga[u]));
					push_heap(q.begin(), q.end());
				}
			}
		}
		return droga[p] < 0;
	}
};

main() {
	ios_base::sync_with_stdio(0);
	mlo m;
}
