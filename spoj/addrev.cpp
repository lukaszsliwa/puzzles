#include <stdio.h>

int n, a, b;

void getint(int& e) {
	char znak;
	while((znak = getchar()) && (znak < '0' || znak > '9'));
	e = znak - '0';
	while((znak = getchar()) && znak >= '0' && znak <= '9')
		e = e * 10 + znak - '0';
}

int reverse(int e) {
	int c, t = 0;
	while(e > 0) {
		c = e % 10;
		e = (e - c) / 10;
		t = t * 10 + c;
	}
	return t;
}

main() {
	getint(n);
	while(n--) {
		getint(a); getint(b);
		printf("%d\n", reverse(reverse(a) + reverse(b)));
	}
}
