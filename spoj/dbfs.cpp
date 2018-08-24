#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
int jest[MAX];

vector<int> graf[MAX];

int input() {
	int t;
	char znak;
	while((znak = getchar_unlocked()) &&
		(znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) &&
		znak >= '0' && znak <= '9')
		t = t * 10 + znak - '0';
	return t;
}

void dfs(int v, int ile) {
	jest[v] = ile;
	printf("%d ", v);
	for(int i = 0; i < graf[v].size(); ++i)
		if(jest[graf[v][i]] != ile)
			dfs(graf[v][i], ile);
}

void bfs(int v, int ile) {
	queue<int> q;
	q.push(v);
	jest[v] = ile;
	while(!q.empty()) {
		v = q.front();
		q.pop();
		printf("%d ", v);
		for(int i = 0; i < graf[v].size(); ++i)
			if(jest[graf[v][i]] != ile) {
				jest[graf[v][i]] = ile;
				q.push(graf[v][i]);
			}
	}
}

int main() {
	int t = input();
	for(int i = 1; i <= t; ++i) {
		int g = 1, n = input();
		for(int x = 1; x < MAX; ++x)
			graf[x].clear();
		while(n--) {
			jest[g++] = -1;
			int p = input(), m = input();
			while(m--) {
				int v = input();
				graf[p].push_back(v);
			}
		}
		int a, b, l = 0;
		printf("graph %d\n", i);
		while(true) {
			a = input(), b = input();
			if(a == 0 && b == 0)
				break;
			l++;
			if(b == 0)
				dfs(a, l);
			else
				bfs(a, l);
			printf("\n");
		}
	}
}
