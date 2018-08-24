#include <stdio.h>
#include <math.h>

main() {
	long long int a, b;
	int c;
	scanf("%d", &c);
	while(c--) {
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", (long long int)sqrt((double)a) * b);
	}
}
