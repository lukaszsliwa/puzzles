// PROG: pie1
// LANG: C++
// ID: C++
#include <cstdio>
#include <queue>

using namespace std;

struct wsp {
	int x, y, koszt;
	wsp() { }
	wsp(int xx, int yy, int kk) : x(xx), y(yy), koszt(kk) { }
	bool operator < (const wsp& W) const {
		return koszt < W.koszt;
	}
};

priority_queue<wsp> q;

const int N_MAX = 102, infty = 1000000;
int n, m, tab[N_MAX][N_MAX];
int ile[N_MAX][N_MAX];

void wczytaj() {
	FILE *in;
	int i, y;
	in = fopen("pie1.in", "r");
	fscanf(in, "%d%d", &n, &m);
	for(i = 1; i <= n; ++i)
		for(y = 1; y <= m; ++y) {
			fscanf(in, "%d", &tab[i][y]);
			ile[i][y] = 0;
		}
	fclose(in);
}

void wrzuc(int x, int y, int koszt) {
	if(x >= 1 && x <= n && y >= 1 && y <= m &&
		tab[x][y] + koszt >= ile[x][y]) {
		q.push(wsp(x, y, tab[x][y] + koszt));
		ile[x][y] = tab[x][y] + koszt;
	}
}

main() {
	FILE *out;
	int x, y, k;
	wczytaj();
	q.push(wsp(1, 1, tab[1][1]));
	ile[1][1] = tab[1][1];
	while(!q.empty()) {
		x = q.top().x;
		y = q.top().y;
		k = q.top().koszt;
		q.pop();
		wrzuc(x - 1, y + 1, k);
		wrzuc(x, y + 1, k);
		wrzuc(x + 1, y + 1, k);
	}
	out = fopen("pie1.out", "w");
	fprintf(out, "%d\n", ile[n][m]);
	fclose(out);
}
