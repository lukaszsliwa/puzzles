#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

const int n_max = 10001;

class shpath {
	int m;
	map<string, int> miasta;
	vector<deque<pair<int, int> > > graf, graf2;
	vector<pair<int, int> > lista;
	bool jest[n_max];

	class sh {
	public:
		int v, koszt;
		sh() {}
		sh(int vv, int kk) {
			v = vv;
			koszt = kk;
		}
		bool operator <(const sh& S) const {
			return koszt > S.koszt;
		}
		sh& operator =(const sh& S) {
			v = S.v;
			koszt = S.koszt;
			return *this;
		}
	};

public:
	shpath() {
		int t, p, waga;
		string text, miasto;
		cin >> t;
		while(t--) {
			cin >> m;
			graf.resize(m + 1);
			graf2.resize(m + 1);
			for(int i = 0; i <= m; ++i)
				jest[i] = false;
			for(int i = 1; i <= m; ++i) {
				cin >> miasto;
				miasta.insert(make_pair(miasto, i));
				cin >> p;
				int a;
				while(p--) {
					cin >> a >> waga;
					graf[i].push_back(make_pair(a, waga));
				}
			}
			int mm;
			cin >> mm;
			string a, b;
			for(int i = 0; i < mm; ++i) {
				cin >> a >> b;
				lista.push_back(make_pair(miasta[a], miasta[b]));
				graf2[miasta[a]].push_back(make_pair(miasta[b], 0));
			}
			for(vector<pair<int, int> >::iterator i = lista.begin();
				i != lista.end(); ++i) {
				if(jest[i->first] == false) {
					dijkstra(i->first);
					jest[i->first] = true;
				}
				cout << graf2[i->first].front().second << endl;
				graf2[i->first].pop_front();
			}
			graf.clear();
			graf2.clear();
			lista.clear();
			miasta.clear();
		}
	}
	void dijkstra(int v) {
		int droga[m];
		for(int i = 0; i <= m; ++i)
			droga[i] = 10000000;
		vector<sh> q;
		q.push_back(sh(v, 0));
		droga[v] = 0;
		sh wierzcholek;
		while(!q.empty()) {
			wierzcholek = q[0];
			pop_heap(q.begin(), q.end());
			q.pop_back();
			for(deque<pair<int, int> >::iterator i = graf[wierzcholek.v].begin();
				i != graf[wierzcholek.v].end(); ++i) {
				if(droga[i->first] > droga[wierzcholek.v] + i->second) {
					droga[i->first] = droga[wierzcholek.v] + i->second;
					q.push_back(sh(i->first, i->second));
					push_heap(q.begin(), q.end());
				}
			}
		}
		for(deque<pair<int, int> >::iterator i = graf2[v].begin();
			i != graf2[v].end(); ++i)
			i->second = droga[i->first];
	}
};

main() {
	ios_base::sync_with_stdio(0);
	shpath s;
}
