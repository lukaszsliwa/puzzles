/*
ID: crh
PROG: factor
LANG: C++
*/
#include <stdio.h>

FILE *in, *out;

main() {
	int i, n, w;
	in = fopen("factor.in", "r");
	out = fopen("factor.out", "a");
	fscanf(in, "%d", &n);
	if(n == 1) {
		fprintf(out, "0\n");
		return 0;
	}
	for(w = 1, i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			w += i;
			if(n / i > i)
				w += (n / i);
		}
	}
	fprintf(out, "%d\n", w);
	fclose(in);
	fclose(out);
}
