#include <iostream>
#include <vector>
using namespace std;

const int n_max = 51;

class dag {
	int n, k, u, v, l, ile[n_max];
	vector<vector<int> > graf;
public:
	dag() : u(0), v(0), k(0) {
		int m, a, b;
		cin >> n >> m >> k;
		graf.resize(n + 1);
		while(m--) {
			cin >> a >> b;
			graf[a].push_back(b);
		}
		wylicz();
	}
	void wylicz() {
		int i, y;
		for(l = 0, i = 1; i <= n; ++i) {
			for(y = 0; y <= n; ++y)
				ile[y] = 0;
			dfs(i, 0);
			for(y = 1; y <= n; ++y)
				if(ile[y] > l) {
					l = ile[y];
					u = i;
					v = y;
				}
		}
	}
	void dfs(int v, int e) {
		if(e == k) {
			ile[v]++;
			return ;
		}
		for(vector<int>::const_iterator i = graf[v].begin();
			i < graf[v].end(); ++i)
			dfs(*i, e + 1);
	}
	~dag() {
		if(u == 0)
			cout << "brak";
		else {
			cout << u << ' ' << v << endl;
			cout << l;
		}
	}
};

main() {
	ios_base::sync_with_stdio(0);
	dag d;
}
