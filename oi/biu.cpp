#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int n_max = 100001;
int n, tab[n_max];

vector< vector<int> > graf;
vector<int> g, wynik, tmp;
queue<int> q;

void readvalue(int& e) {
	char znak;
	while((znak = getchar()) < '0' || znak > '9');
	e = znak - '0';
	while((znak = getchar()) >= '0' && znak <= '9')
		e = 10 * e + znak - '0';
}

void wczytaj() {
	int a, b, m;
	readvalue(n); readvalue(m);
	graf.resize(n + 1);
	while(m--) {
		readvalue(a); readvalue(b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
}

void biurowce() {
	int i, v, u, pozycja = 0;
	for(i = n; i >= 1; --i)
		q.push(i);
	while(!q.empty()) {
		if(g.empty()) {
			g.push_back(q.front());
			q.pop();
		}
		if(pozycja < g.size()) {
			v = g[pozycja++];
			for(i = 0; i < graf[v].size(); ++i)
				tab[graf[v][i]] = v;
			while(!q.empty()) {
				u = q.front();
				if(tab[u] != v)
					g.push_back(u);
				else
					tmp.push_back(u);
				q.pop();
			}
			while(!tmp.empty()) {
				q.push(tmp.back());
				tmp.pop_back();
			}
		} else {
			wynik.push_back(g.size());
			g.clear();
			pozycja = 0;
		}
	}
	if(!g.empty())
		wynik.push_back(g.size());
}

void odpowiedz() {
	int i;
	printf("%d\n", wynik.size());
	sort(wynik.begin(), wynik.end());
	for(i = 0; i < wynik.size(); ++i)
		printf("%d ", wynik[i]);
	printf("\n");
}

int main() {
	wczytaj();
	biurowce();
	odpowiedz();
	return 0;
}
