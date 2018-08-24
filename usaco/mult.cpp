/*
ID: crh
PROG: mult
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#define ile_cyfr(X) \
	(int)floor(log10((float)(X))) + 1

void odstep(int n, int i) {
	int l = n - i;
	while(l--)
		putchar(' ');
}

FILE *in, *out;

main() {
	int i, y, n, x, len;
	in = fopen("mult.in", "w");
	out = fopen("mult.out", "a");
	fscanf(in, "%d", &n);
	len = ile_cyfr(n * n) + 1;
	odstep(ile_cyfr(n), 1);
	fprintf(out, "*");
	for(i = 1; i <= n; ++i) {
		odstep(len, ile_cyfr(i));
		fprintf(out, "%d", i);
	}
	fprintf(out, "\n");
	for(i = 1; i <= n; ++i) {
		odstep(ile_cyfr(n), ile_cyfr(i));
		fprintf(out, "%d", i);
		for(y = 1, x = i; y <= n; ++y) {
			odstep(len, ile_cyfr(x));
			fprintf(out, "%d", x);
			x += i;
		}
		fprintf(out, "\n");
	}
	fclose(in);
	fclose(out);
}
