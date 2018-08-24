#include <cstdio>
using namespace std;

bool tab[231];

int main() {
	int i, s, n;
	for(i = 1, s = 1; s < 231; i++) {
		tab[s] = true;
		s += i;
	}
	scanf("%d", &n);
	while(n--) {
		int m;
		scanf("%d", &m);
		printf("%d ", tab[m]);
	}
}
