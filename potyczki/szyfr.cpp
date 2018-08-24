#include <stdio.h>

main() {
	long long int n, m, a, b, t;
	int i;
	scanf("%lld%lld", &n, &m);
	a = b = 1;
	if(n == 1)
		printf("11");
	if(n == 2)
		printf("1");
	for(i = 3; i <= m; ++i) {
		t = (a + b) % 10;
		if(i >= n)
			printf("%lld", t);
		a = b;
		b = t;
	}
	printf("\n");
}
