#include <stdio.h>

long long int getint() {
	char znak;
	long long int t;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) && znak <= '9' && znak >= '0')
		t = t * 10 + znak - '0';
	return t;
}

main() {
	long long int n, l;
	n = getint();
	while(n--) {
		l = getint() - 1;
		if(l == 0)
			puts("192");
		else
			printf("%lld\n", 442 + (l - 1) * 250);
	}
}
