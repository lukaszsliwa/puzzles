#include <cstdio>
using namespace std;

int nwd(int a, int b) {
	while(b) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", nwd(a, b));
	}
}
