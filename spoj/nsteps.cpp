#include <stdio.h>
#include <math.h>

int getint() {
	int t; char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) && znak <= '9' && znak >= '0')
		t = t * 10 + znak - '0';
	return t;
}

main() {
	int a, b, n;
	n = getint();
	while(n--) {
		a = getint();
		b = getint();
		if(a == b)
			printf("%d\n", 2 * a - (a % 2));
		else if(a - 2 == b)
			printf("%d\n", 2 * b + 2 - (b % 2));
		else
			puts("No Number");
	}
}
