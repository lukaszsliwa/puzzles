#include <cstdio>

int main() {
	int t, l, c;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &l, &c);
		if(l == 1 && c == 0)
			printf("NIE\n");
		else if(l == 1 && c != 0)
			printf("TAK\n");
		else
			printf(c % (l - 1) == 0 ? "NIE\n" : "TAK\n");
	}
}
