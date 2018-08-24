#include <stdio.h>

using namespace std;

const int N_MAX = 1001;
const int infty = 1000000;
int n, m, a, b, skoki[N_MAX][N_MAX];
char tab[N_MAX][N_MAX];
bool jest[N_MAX][N_MAX];

struct wsp {
	int x, y;
	wsp() { }
	wsp(int xx, int yy) {
		x = xx;
		y = yy;
	}
} start, koniec;

struct queue {
	int index, end;
	bool empty_q;

	wsp tab[N_MAX * N_MAX];
	queue() {
		index = end = 0;
		empty_q = true;
	}
	void push(wsp e) {
		tab[end].x = e.x;
		tab[end++].y = e.y;
	}
	void pop() {
		index++;
	}
	bool empty() {
		index > end ? empty_q = true : empty_q = false;
		return empty_q;
	}
	wsp front() {
		return tab[index];
	}
} q;

int getint() {
	int t;
	char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) && znak <= '9' && znak >= '0')
		t = t * 10 + znak - '0';
	return t;
}

void wczytaj() {
	int i, y;
	n = getint();
	m = getint();
	a = getint();
	b = getint();
	for(i = 1; i <= n; ++i) {
		for(y = 1; y <= m; ++y) {
			tab[y][i] = getchar_unlocked();
			skoki[y][i] = infty;
			if(tab[y][i] == 'S') {
				start.x = y;
				start.y = i;
			} else if(tab[y][i] == 'K') {
				koniec.x = y;
				koniec.y = i;
			}
		}
		getchar_unlocked();
	}
}

void dodaj(int x, int y, int ile) {
	if(x >= 1 && x <= m && y >= 1 && y <= n 
		&& tab[x][y] != 'X' && !jest[x][y]) {
		q.push(wsp(x, y));
		skoki[x][y] = ile + 1;
		jest[x][y] = true;
	}
}

int skok() {
	int ile = 0, x, y;
	wsp punkt;
	q.push(wsp(start.x, start.y));
	skoki[start.x][start.y] = 0;
	while(!q.empty() && !jest[koniec.x][koniec.y]) {
		punkt.x = q.front().x;
		punkt.y = q.front().y;
		//printf("[%d][%d] = %d\n", punkt.x, punkt.y, skoki[punkt.x][punkt.y]);
		q.pop();
		ile = skoki[punkt.x][punkt.y];
		dodaj(punkt.x + a, punkt.y + b, ile);
		dodaj(punkt.x - a, punkt.y + b, ile);
		dodaj(punkt.x + a, punkt.y - b, ile);
		dodaj(punkt.x - a, punkt.y - b, ile);
		dodaj(punkt.x + b, punkt.y + a, ile);
		dodaj(punkt.x - b, punkt.y + a, ile);
		dodaj(punkt.x + b, punkt.y - a, ile);
		dodaj(punkt.x - b, punkt.y - a, ile);
	}
	return skoki[koniec.x][koniec.y] == infty;
}

main() {
	wczytaj();
	skok() ? printf("NIE\n") : printf("%d\n", skoki[koniec.x][koniec.y]);
}
