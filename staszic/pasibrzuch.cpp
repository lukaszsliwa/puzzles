#include <cstdio>
#include <list>
#include <queue>
using namespace std;

const int n_max = 301;
const int infty = 1000000000;

struct punkt {
	int x, y, koszt;
	punkt() {}
	punkt(int xx, int yy, int kk) {
		x = xx;
		y = yy;
		koszt = kk;
	}
	punkt& operator = (const punkt& P) {
		x = P.x;
		y = P.y;
		koszt = P.koszt;
		return *this;
	}
};

struct paczka {
	int size;
	punkt p[10];
	paczka() : size(0) {}
} ile[n_max][n_max];

class pasibrzuch {
	struct wie {
		int x, y, a, b, koszt;
		wie() : koszt(0) {}
		wie(int xx, int yy, int aa, int bb, int kk) {
			x = xx;
			y = yy;
			a = aa;
			b = bb;
			koszt = kk;
		}
		wie& operator = (const wie& W) {
			x = W.x;
			y = W.y;
			a = W.a;
			b = W.b;
			koszt = W.koszt;
			return *this;
		}
	};

	char tab[n_max][n_max];
	punkt start, koniec;

	int n, m;
public:
	pasibrzuch() {
		char wiersz[n_max];
		scanf("%d%d\n", &n, &m);
		for(int i = 1; i <= n; ++i) {
			scanf("%s", wiersz);
			for(int y = 1; y <= m; ++y) {
				tab[y][i] = wiersz[y - 1];
				obszar(y, i);
				if(tab[y][i] == 'S')
					start = punkt(y, i, 0);
				else if(tab[y][i] == 'K')
					koniec = punkt(y, i, 0);
			}
		}
	}
	void push(int a, int b, int x, int y, int k) {
		int size = ile[a][b].size;
		ile[a][b].p[size].x = x;
		ile[a][b].p[size].y = y;
		ile[a][b].p[size].koszt = k;
		ile[a][b].size++;
	}
	bool poprawny(int x, int y) {
		return x >= 1 && x <= m && y >= 1 && y <= n && tab[x][y] != 'X';
	}
	void dodaj_obszar(int a, int b, int x, int y) {
		if(poprawny(x, y))
			push(a, b, x, y, infty);
	}
	void obszar(int x, int y) {
		dodaj_obszar(x, y, x - 1, y + 1);
		dodaj_obszar(x, y, x, y + 1);
		dodaj_obszar(x, y, x + 1, y + 1);
		dodaj_obszar(x, y, x - 1, y);
		dodaj_obszar(x, y, x + 1, y);
		dodaj_obszar(x, y, x - 1, y - 1);
		dodaj_obszar(x, y, x, y - 1);
		dodaj_obszar(x, y, x + 1, y - 1);
	}
	bool kat45(int x1, int y1, int x2, int y2, int x3, int y3) {
		return	(x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) < 0;
	}
	int find(int a, int b, int x, int y, int k = -1) {
		for(int i = 0; i != ile[a][b].size; ++i) {
			if(ile[a][b].p[i].x == x && ile[a][b].p[i].y == y) {
				if(k > -1)
					ile[a][b].p[i].koszt = k;
				return ile[a][b].p[i].koszt;
			}
		}
		return 0;
	}
	
	queue<wie> q;

	void wrzuc(const wie& e, int x, int y) {
		if(poprawny(x, y) && kat45(e.a, e.b, e.x, e.y, x, y) &&
			find(x, y, e.x, e.y) == infty) {
			find(x, y, e.x, e.y, e.koszt + 1);
			q.push(wie(x, y, e.x, e.y, e.koszt + 1));
		}
	}
	int oblicz() {
		for(int i = 0; i != ile[start.x][start.y].size; ++i)
			q.push(wie(ile[start.x][start.y].p[i].x, 
				ile[start.x][start.y].p[i].y, start.x, start.y, 1));
		while(!q.empty()) {
			wie v = q.front();
			//printf("z (%d ; %d) na (%d ; %d)\n", v.a, v.b, v.x, v.y);
			q.pop();
			wrzuc(v, v.x - 1, v.y + 1);
			wrzuc(v, v.x - 1, v.y);
			wrzuc(v, v.x - 1, v.y - 1);
			wrzuc(v, v.x, v.y + 1);
			wrzuc(v, v.x, v.y - 1);
			wrzuc(v, v.x + 1, v.y + 1);
			wrzuc(v, v.x + 1, v.y);
			wrzuc(v, v.x + 1, v.y - 1);
		}
		int wynik = infty;
		for(int i = 0; i != ile[koniec.x][koniec.y].size; ++i)
				wynik = min(wynik, ile[koniec.x][koniec.y].p[i].koszt);
		return wynik;
	}
	~pasibrzuch() {
		int t;
		if((t = oblicz()) != infty)
			printf("%d\n", t);
		else
			printf("NIE\n");
	}
};

main() {
	pasibrzuch p;
}
