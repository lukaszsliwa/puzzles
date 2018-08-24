#include <stdio.h>

inline void get(int& x, int& y) {
	scanf("%d%d", &x, &y);
}

#define text(S) printf("%s = %d\n", #S, S);

void kat45(int x1, int y1, int x2, int y2, int x3, int y3) {
	text(int a = (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2));
	text(int b = (x1 - x2) * (y2 - y2) - (x3 - x2) * (y1 - y2));
}

main() {
	int x1, x2, x3, y1, y2, y3;
	get(x1, y1);
	get(x2, y2);
	get(x3, y3);
	kat45(x1, y1, x2, y2, x3, y3);
}
