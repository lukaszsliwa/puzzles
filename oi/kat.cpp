#include <stdio.h>
#include <math.h>

double a1, a2, a3, b1, b2, b3;
double pi = 3.14;

double pot(double e) {
	return e * e;
}

double kat() {
	double licznik, mianownik;
	licznik = pot(a1 - b1) + pot(b1 - b2) + pot(a3 - a2) + pot(b3 - b2) - pot(a1 + a3 - 2 * a2) - pot(b1 + b3 - 2 * b2);
	mianownik = (double)sqrt((pot(a1 - a2) + pot(b1 - b2)) * (pot(a3 - a2) + pot(b3 - b2)));
	return acos(licznik / mianownik) * 180 / pi;
}

main() {
	scanf("%lf%lf%lf", &a1, &a2, &a3);
	scanf("%lf%lf%lf", &b1, &b2, &b3);
	printf("%lf\n", kat());
}
