// PROG: skate
// LANG: C++
// ID: C++

#include <cstdio>
#include <queue>

using namespace std;

const int N_MAX = 114;
int n, m;
char tab[N_MAX][N_MAX];

FILE *out;

struct wsp {
	int x, y;
	wsp() { x = y = -1; }
	wsp(int xx, int yy) : x(xx), y(yy) { }
} T[N_MAX][N_MAX];

queue<wsp> q;

void wczytaj() {
	int i, y;
	FILE *in;
	in = fopen("skate.in", "r");
	fscanf(in, "%d%d", &n, &m);
	for(i = 0; i < n; ++i)
		fscanf(in, "%s", tab[i]);
	fclose(in);
}

void wrzuc(queue<wsp>& t, int x, int y, int v, int w) {
	if(x >= 0 && x < n && y >= 0 && y < m &&
		tab[x][y] != '*') {
		tab[x][y] = '*';
		t.push(wsp(x, y));
		T[x][y].x = v;
		T[x][y].y = w;
	}
}

void bfs(int x, int y) {
	q.push(wsp(x, y));
	tab[x][y] = '*';
	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		q.pop();
		if (x == n - 1 && y == m - 1)
			return ;
		wrzuc(q, x - 1, y, x, y);
		wrzuc(q, x + 1, y, x, y);
		wrzuc(q, x, y - 1, x, y);
		wrzuc(q, x, y + 1, x, y);
	}
}

void drukuj(int x, int y) {
	if(x != -1 && y != -1) {
		drukuj(T[x][y].x, T[x][y].y);
		fprintf(out, "%d %d\n", x + 1, y + 1);
	}
}

main() {
	wczytaj();
	bfs(0, 0);
	out = fopen("skate.out", "w");
	drukuj(n - 1, m - 1);
	fclose(out);
}
