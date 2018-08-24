/*
ID: crh
PROG: names
LANG: C++
*/
#include <stdio.h>

char n[32], s[32];
FILE *in, *out;

main() {
	in = fopen("names.in", "r");
	out = fopen("names.out", "a");
	fscanf(in, "%s %s", n, s);
	fprintf(out, "%s, %s\n", s, n);
	fclose(in);
	fclose(out);
}
