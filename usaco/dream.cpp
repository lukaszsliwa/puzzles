// ID: 3crhash1
// PROG: dream
// LANG: C++
#include <stdio.h>

FILE *in, *out;

int cyfra[11];

main() {
	long long i, j, l;
	in = fopen("dream.in", "r");
	fscanf(in, "%lld%lld", &i, &j);
	fclose(in);
	for(; i <= j; ++i) {
		l = i;
		while(l > 0) {
			cyfra[l % 10]++;
			l = (l - l % 10) / 10;
		}
	}
	out = fopen("dream.out", "w");
	for(i = 0; i < 9; ++i)
		fprintf(out, "%d ", cyfra[i]);
	fprintf(out, "%d\n", cyfra[9]);
}
