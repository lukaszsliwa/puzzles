#include <cstdio>
#include <stack>

using namespace std;

const int N_MAX = 202;
int pewniak[N_MAX];

stack<int> tmp;

int main() {
	int z, n, m, w, l, ile, nr;
	char znak;
	scanf("%d", &z);
	while(z--) {
		scanf("%d%d", &n, &m);
		while(m--) {
			scanf("%d", &w);
			printf("%d\n", w);
			w *= 2;
			while(w--) {
				scanf("%d", &l);
				tmp.push(l);
			}
			scanf("\n%c\n", &znak);
			printf("%c\n", (char)znak);
			if(znak == '=') {
				while(!tmp.empty()) {
					pewniak[tmp.top()] = z + 1;
					tmp.pop();
				}
			} else 
				while(!tmp.empty()) tmp.pop();
		}
		ile = 0;
		nr = -1;
		for(int i = 1; i <= n; ++i)
			if(pewniak[i] == z + 1) {
				ile++;
				nr = i;
			}
		ile == 1 ? printf("%d\n", nr) : printf("NIE\n");
	}
	return 0;
}
