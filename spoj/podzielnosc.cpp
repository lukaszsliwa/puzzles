#include <cstdio>
using namespace std;

int main() {
	int x, y, n, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &x, &y);
		for(int i = 2; i < n; ++i)
			if((i % x == 0) && (i % y != 0))
				printf("%d ", i);
		printf("\n");
	}
}
