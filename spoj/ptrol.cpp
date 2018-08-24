#include <stdio.h>

int getint() {
	char znak;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	int l = znak - '0';
	while((znak = getchar_unlocked()) && znak >= '0' && znak <= '9')
		l = l * 10 + znak - '0';
	return l;
}

int main() {
	int a, t, len;
	t = getint();
	while(t--) {
		len = getint();
		a = getint();
		while(--len)
			printf("%d ", getint());
		printf("%d\n", a);
	}
}
