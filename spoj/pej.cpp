#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m, **jest;
char **tab;

void wczytaj() {
	cin >> n >> m;
	tab = new char*[n + 1];
	jest = new int*[n + 1];
	for(int i = 0; i < n; ++i) {
		tab[i] = new char[m + 1];
		jest[i] = new int[m + 1];
		cin >> tab[i];
	}
}

struct para {
	int x, y;
	para(int xx, int yy) : x(xx), y(yy) {}
};

queue<para> q;

int max(int& a, int& b) {
	return a > b ? a : b;
}

int licz(int x, int y) {
	return x > 0 ? (x - 1) * m + y : y;
}

void wrzuc(queue<para>& q, int x, int y, int numer, char znak) {
	if(x >= 0 && x < n && y >= 0 && y < m &&
			jest[x][y] == 0 && tab[x][y] == znak) {
		jest[x][y] = numer;
		q.push(para(x, y));
	}
}

void zapusc(int x, int y, int numer, char znak) {
	q.push(para(x, y));
	jest[x][y] = numer;
	while(!q.empty()) {
		int i = q.front().x, j = q.front().y;
		q.pop();
		wrzuc(q, i - 1, j + 1, numer, znak);
		wrzuc(q, i - 1, j, numer, znak);
		wrzuc(q, i - 1, j - 1, numer, znak);
		wrzuc(q, i, j + 1, numer, znak);
		wrzuc(q, i, j - 1, numer, znak);
		wrzuc(q, i + 1, j + 1, numer, znak);
		wrzuc(q, i + 1, j, numer, znak);
		wrzuc(q, i + 1, j - 1, numer, znak);
	}
}

int bfs(char znak) {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			jest[i][j] = 0;
	int skladowa = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			if(jest[i][j] == 0 && tab[i][j] == znak) {
				zapusc(i, j, skladowa++, znak);
			}
	}
	int r = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			r = max(r, jest[i][j]);
	return r;
}

bool pusty(char znak) {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(tab[i][j] != znak)
				return false;
	return true;
}

int main() {
	int a, b;
	wczytaj();
	if(pusty('.') || pusty('X'))
		printf("0\n");
	else
		printf("%d\n", min(bfs('.'), bfs('X')));
}
