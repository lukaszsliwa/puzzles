#include <cstdio>
#include <queue>
using namespace std;

class punkt {
public:
	int x, y;
	punkt(int xx, int yy) : x(xx), y(yy) {}
	punkt& operator = (const punkt& P) {
		x = P.x;
		y = P.y;
		return *this;
	}
};

class k {
public:
	int waga;
	punkt v, prev;
	k(punkt a, punkt b, int w) : v(a), prev(b), waga(w) {}
	bool operator < (const k& K) const {
		return waga > K.waga;
	}
};

priority_queue<k> q;

void wczytaj() {
	scanf("%d%d\n", &n, &m);
	for(i = 1; i <= n; ++i) {
		for(y = 1; y <= m; ++y)
			scanf("%c", &tab[i][y]);
		getchar();
	}
}

main() {
	wczytaj();
}
