#include <stdio.h>

void getint(int& e) {
	char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	e = znak - '0';
	while((znak = getchar_unlocked()) && znak >= '0' && znak <= '9')
		e = e * 10 + znak - '0';
}

int compute(int e) {
	int c = 0, n = e;;
	while(e > 0) {
		c += e % 5;
		e /= 5;
	}
	return (n - c) / 4;
}

main() {
	int n, m;
	getint(n);
	while(n--) {
		getint(m);
		printf("%d\n", compute(m));
	}
}
