#include <stdio.h>

long long int n;

main() {
	scanf("%lld", &n);
	printf("%lld\n", n * (n + 1) / 2);
}
