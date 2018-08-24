#include <stdio.h>

int power(int& a, int& b, int& c) {
	int s;
	if(b == 0)
		return 1;
	for(s = a; b > 1; --b) {
		s *= a;
		s %= c;
	}
	return s % c;
}

int main() {
	int t, x, n, p;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &x, &n, &p);
		printf("%d\n", power(x, n, p));
	}
}
