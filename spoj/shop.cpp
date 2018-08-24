#include <cstdio>
#include <queue>

using namespace std;

struct punkt {
	int x, y, koszt;
	punkt() { }
	punkt(int xx, int yy, int kk = 0) {
		x = xx;
		y = yy;
		koszt = kk;
	}
	bool operator <(const punkt& P) const {
		return koszt < P.koszt;
	}
} s, d;

priority_queue<punkt> q;

const int n_max = 26, infty = 10000000;
int n, m, tab[n_max][n_max], koszty[n_max][n_max];

void wrzuc(int bx, int by, int ax, int ay) {
	if(bx >= 0 && bx < m && by >= 0 && by < n 
		&& tab[bx][by] != -1 && koszty[ax][ay] + tab[bx][by] < koszty[bx][by]) {
		koszty[bx][by] = koszty[ax][ay] + tab[bx][by];
		q.push(punkt(bx, by, koszty[bx][by]));
	}
}

int dijkstra(punkt& S, punkt& D) {
	punkt v;
	bool stop = false;
	q.push(punkt(S.x, S.y, 0));
	koszty[S.x][S.y] = 0;
	while(!q.empty() && !stop) {
		v.x = q.top().x;
		v.y = q.top().y;
		q.pop();
		wrzuc(v.x, v.y + 1, v.x, v.y);
		wrzuc(v.x, v.y - 1, v.x, v.y);
		wrzuc(v.x + 1, v.y, v.x, v.y);
		wrzuc(v.x - 1, v.y, v.x, v.y);
	}
	return koszty[D.x][D.y];
}

main() {
	int i, j;
	char znak;
	while(scanf("%d%d", &n, &m) && n != 0 && m != 0) {
		for(i = 0; i < m; ++i) {
			scanf("%c", &znak);
			for(j = 0; j < n; ++j) {
				scanf("%c", &znak);
				koszty[i][j] = infty;
				tab[i][j] = 0;
				if(znak == 'X')
					tab[i][j] = -1;
				else if(znak == 'S') {
					s.x = i;
					s.y = j;
				} else if(znak == 'D') {
					d.x = i;
					d.y = j;
				} else
					tab[i][j] = znak - '0';
			}
		}
		scanf("%c", &znak);
		printf("%d\n", dijkstra(s, d));
	}
}
