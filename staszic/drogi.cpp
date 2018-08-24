#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int N_MAX = 10001;
int n, m, s = 0, in, out;
int czasy[N_MAX], skladowa[N_MAX];
bool jest[N_MAX];

vector< set<int> > g, f, skl_in, skl_out;

void wczytaj() {
	int a, b;
	scanf("%d%d", &n, &m);
	g.resize(n + 1);
	f.resize(n + 1);
	while(m--) {
		scanf("%d%d", &a, &b);
		if(a != b) {
			g[a].insert(b);
			f[b].insert(a);
		}
	}
}

void dfs(vector< set<int> >& p, int v, int c[], int co) {
	jest[v] = true;
	for(set<int>::iterator y = p[v].begin(); y != p[v].end(); ++y)
		if(jest[*y] == false)
			dfs(p, *y, c, co);
	co == 0 ? c[s++] = v : skladowa[v] = co;
}

int main() {
	int i, q;
	wczytaj();
	for(i = 0; i <= n; ++i)
		jest[i] = false;
	for(i = 1; i <= n; ++i)
		if(jest[i] == false)
			dfs(g, i, czasy, 0);
	for(i = 0; i <= n; ++i)
		jest[i] = false;
	for(i = s - 1, q = 0; i >= 0; --i)
		if(jest[czasy[i]] == false)
			dfs(f, czasy[i], czasy, ++q);
	if(q == 1) {
		printf("0\n");
		return 0;
	}
	/*for(i = 1; i <= n; ++i)
		printf("skladowa[%d]= %d\n", i, skladowa[i]);*/
	skl_in.resize(q + 1);
	skl_out.resize(q + 1);
	for(i = 1; i <= n; ++i) {
		for(set<int>::iterator y = g[i].begin(); y != g[i].end(); ++y)
			if(skladowa[i] != skladowa[*y]) {
				skl_in[skladowa[*y]].insert(skladowa[i]);
				skl_out[skladowa[i]].insert(skladowa[*y]);
			}
	}
	for(i = 1, in = out = 0; i <= q; ++i) {
		if(skl_in[i].size() == 0)
			in++;
		if(skl_out[i].size() == 0)
			out++;
	}
	printf("%d\n", in == out && in % 2 != 0 ? max(in, out) + 1 : max(in, out));
	return 0;
}
