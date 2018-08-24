#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int l, a, s = 0;
		scanf("%d", &l);
		while(l--) {
			scanf("%d", &a);
			s += a;
		}
		printf("%d\n", s);
	}
}
