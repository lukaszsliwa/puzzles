#include <cstdio>
#include <cstring>

using namespace std;

int pi[1000002];
char tab[1000002];

int get_string(char t[]) {
	char znak; int len = 1;
	scanf("%s", tab);
	len = strlen(tab);
	for(int i = len - 1; i >= 0; --i)
		tab[i + 1] = tab[i];

	return len;
}

void prefix(int len) {
	pi[1] = 0;
	int k = 0;
	for(int q = 2; q <= len; ++q) {
		while(k > 0 && tab[k + 1] != tab[q])
			k = pi[k];
		if(tab[k + 1] == tab[q])
			k++;
		pi[q] = k;
	}
	for(int i = 1; i <= len; ++i)
		printf("%d ", pi[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	getchar_unlocked();
	while(t--)
		prefix(get_string(tab));
}
