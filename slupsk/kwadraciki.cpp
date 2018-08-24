#include <stdio.h>

long long int n, m, a, b, c;

main() {
	scanf("%lld", &m);
	while(m--) {
		scanf("%lld", &n);
		a = n;
		b = n + 1;
		c = 2*n + 1;
		if(c % 6 == 0)
			c /= 6;
		else if(b % 6 == 0)
			b /= 6;
		else if(a * b % 6 == 0) {
			b = a * b / 6;
			a = 1;
		} else if(a * c % 6 == 0) {
			c = a * c / 6;
			a = 1;
		} else if(b * c % 6 == 0) {
			c = b * c / 6;
			b = 1;
		} else  { 
			c = a * b * c / 6;
			a = b = 1;
		}
		printf("%lld\n", a * b * c);
	}
}
