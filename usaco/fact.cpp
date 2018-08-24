// ID: 3crhash1
// PROG: fact
// LANG: C++
#include <stdio.h>

FILE *in, *out;

main() {
	int n, i;
	long long int y;
	in = fopen("fact.in", "r");
	out = fopen("fact.out", "w");
	fscanf(in, "%d", &n);
	for(i = 1, y = 1; i <= n; ++i)
		y *= i;
	fprintf(out, "%lld\n", y);
	fclose(in);
	fclose(out);
}
