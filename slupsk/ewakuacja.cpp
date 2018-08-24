#include <iostream>
#include <utility>
#include <vector>
#include <list>
using namespace std;

const int n_max = 1001;

class kra {
public:
	int w, c;
	kra(int ww, int cc) : w(ww), c(cc) {}
};

typedef list<kra>::iterator list_iter;

class ewakuacja {
	int n, p0, pk;
	vector<list<kra> > graf;
public:
	ewakuacja() {
		int m, a, b, p;
		cin >> n >> m >> p0 >> pk;
		graf.resize(n + 1);
		while(m--) {
			cin >> a >> b >> p;
			graf[a].push_back(kra(b, p));
		}
	}
	~ewakuacja() {
		cout << maksymalny_przeplyw() << endl;
	}
	bool sciezka_rozszerzajaca(int t[]) {
		int q[n_max], q_len = 0;
		bool jest[n_max];
		for(int i = 0; i <= n; ++i)
			jest[i] = t[i] = 0;
		q[q_len++] = p0;
		jest[p0] = true;
		t[p0] = -1;
		while(q_len--) {
			int v = q[q_len];
			for(list_iter y = graf[v].begin();
				y != graf[v].end(); ++y)
				if(y->c > 0 && jest[y->w] == false) {
					jest[y->w] = true;
					t[y->w] = v;
					q[q_len++] = y->w;
				}
		}
		return t[pk] != 0;
	}
	int find_c(int a, int b, int r) {
		list_iter i;
		for(i = graf[a].begin(); i != graf[a].end(); ++i)
			if(i->c > 0 && i->w == b)
				return (i->c -= r);
		return 0;
	}
	int minimalna_przepustowosc(int t[]) {
		int r = find_c(t[pk], pk, 0), v = pk;
		while(t[v] != -1) {
			r <?= find_c(t[v], v, 0);
			v = t[v];
		}
		return r;
	}
	int maksymalny_przeplyw() {
		int pi[n_max], wynik = 0;
		while(sciezka_rozszerzajaca(pi)) {
			int v = pk, c_min = minimalna_przepustowosc(pi);
			while(pi[v] != -1) {
				//cout << pi[v] << ' ' << v << endl;
				find_c(pi[v], v, c_min);
				v = pi[v];
			}
			wynik += c_min;
		}
		return wynik;
	}
};

main() {
	ewakuacja e;
}
