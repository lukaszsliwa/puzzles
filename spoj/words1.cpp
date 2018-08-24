#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int znaki[30];

vector<int> graf[30];

void getint(int& e) {
	char znak;
	while((znak = getchar()) && (znak < '0' || znak > '9'));
	e = znak - '0';
	while((znak = getchar()) && znak >= '0' && znak <= '9')
		e = e * 10 + znak - '0';
}

void getstring(char& a, char& b) {
	char znak;
	while((znak = getchar()) && (znak < 'a' || znak > 'z'));
	a = znak;
	while((znak = getchar()) && znak >= 'a' && znak <= 'z')
		b = znak;
}

int jest[30], top[30], t_len = 0, R = 0, r;

void dfs(int p, int v) {
	jest[v] = p;
	for(int i = 0; i < graf[v].size(); ++i)
		if(v != graf[v][i] && jest[graf[v][i]] != p)
			dfs(p, graf[v][i]);
	top[t_len++] = v;
}

void door(int v) {
	int t;
	R++;
	while(!graf[v].empty()) {
		t = graf[v].back();
		graf[v].pop_back();
		door(t);
		printf("%c ", t + 'a' - 1);
	}
}

bool check(int p) {
	int i;
	R = t_len = 0;
	for(i = 1; i <= 26; ++i)
		if(jest[i] != p && !graf[i].empty())
			dfs(p, i);
	/*for(i = 0; i < t_len; ++i)
		printf("%c ", top[i] + 'a' - 1);
	printf("\n");*/
	door(top[t_len - 1]);
	return r == R + 1;
}

int val(char& z) {
	return z - 'a' + 1;
}

main() {
	int n, m;
	char a, b;
	getint(n);
	while(n--) {
		getint(m);
		r = m;
		while(m--) {
			getstring(a, b);
			graf[val(a)].push_back(val(b));
		}
		printf(check(n + 1) ? "Ordering is possible.\n" : "The door cannot be opened.\n");
	}
}
