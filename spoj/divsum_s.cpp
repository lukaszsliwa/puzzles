#include <stdio.h>
int getint() {
	int a;
	char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	a = znak - '0';
	while((znak = getchar_unlocked()) && znak <= '9' && znak >= '0')
		a = a * 10 + znak - '0';
	return a;
}

main() {
	int t;
	t = getint();
	while(t--)
		printf("%d\n", tab[getint() - 1]);
}