// ID: 3crhash1
// PROG: tax
// LANG: C++
#include <stdio.h>
#include <math.h>

FILE *in, *out;

main() {
	int n, p, w;
	double wynik, calkowita, reszta;
	in = fopen("tax.in", "r");
	out = fopen("tax.out", "w");
	fscanf(in, "%d%d", &n, &p);
	wynik = (double)((double)n * (double)p / 100.0);
	reszta = modf(wynik, &calkowita);
	if(reszta < 0.5)
		w = (int)wynik;
	else
		w = (int)(wynik) + 1;
	fprintf(out, "%d\n", w);
	fclose(in);
	fclose(out);
}
