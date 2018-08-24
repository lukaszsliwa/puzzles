// ID: 3crhash1
// PROG: mgraph
// LANG: C++
#include <stdio.h>

FILE *f, *p;

main() {
	int n, d;
	f = fopen("mgraph.in", "r");
	p = fopen("mgraph.out", "w");
	fscanf(f, "%d", &n);
	while(n--) {
		fscanf(f, "%d", &d);
		if(d < 10)
			fprintf(p, " ");
		fprintf(p, "%d ", d);
		while(d--)
			fprintf(p, "*");
		fprintf(p, "\n");
	}
	fclose(f);
	fclose(p);
}
