#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const double infty = 100000000.0;
const int n_max = 100001;
const double pi =  3.14159265;

struct wsp {
	double x, y;
	wsp() : x(infty), y(infty) { }
	wsp(double& xx, double& yy) : x(xx), y(yy) { }
};

vector<wsp> figura;
int n, pi_tab[n_max], rad[n_max];
double katy[n_max], katy_re[n_max];

int Min(int x, int y) {
	return x < y ? x : y;
}

int Max(int x, int y) {
	return x < y ? y : x;
}

double odleglosc(wsp& a, wsp& b) {
	return (double)(sqrt(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0)));
}

double det(wsp& a, wsp& b, wsp& c) {
	return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

double oblicz_kat(wsp& a, wsp& b, wsp& c) {
	double odl_a, odl_b, odl_c, r;
	odl_a = odleglosc(a, b);
	odl_b = odleglosc(b, c);
	odl_c = odleglosc(a, c);
	r = (pow(odl_a, 2.0) +  pow(odl_b, 2.0) - pow(odl_c, 2.0)) / (2.0 * odl_a * odl_b);
	if(det(a, b, c) > 0.0)
		return 360.0 - acos(r) * 180 / pi;
	return acos(r) * 180 / pi;
}

void wczytaj() {
	int i;
	double a, b;
	scanf("%d", &n);
	figura.push_back(wsp());
	for(i = 0; i < n; ++i) {
		scanf("%lf%lf", &a, &b);
		figura.push_back(wsp(a, b));
	}
}

void alfa_f() {
	int i, last;
	last = n;
	for(i = 1; i < figura.size() - 1; ++i) {
		katy[i] = oblicz_kat(figura[last], figura[i], figura[i + 1]);
		last = i;
	}
	katy[n] = oblicz_kat(figura[n - 1], figura[n], figura[1]);
	/*for(i = 1; i <= n; ++i)
		printf("%.0lf ", katy[i]);
		printf("\n");
	for(i = n; i >= 1; --i)
		printf("%.0lf ", katy[i]);
		printf("\n");*/
}

bool foremny() {
	int i;
	for(i = 2; i <= n; ++i)
		if(katy[i] != katy[i - 1])
			return false;
	return true;
}

void odwroc() {
	int i, j;
	for(i = 1, j = n; i <= n; ++i, --j)
		katy_re[i] = katy[j];
}

bool sprawdz(int j) {
	int i;
	for(i = 1; j <= n; ++i, ++j)
		if(katy[j] != katy_re[i])
			return false;
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		wczytaj();
		alfa_f();
		if(foremny())
			printf("%d\n", n);
		else {
			odwroc();
			//prefix();
			//kmp();
			//printf("0\n");
			int i, R = 0;
			for(i = 1; i <= n; ++i) {
				if(sprawdz(i))
					R++;
			}
			printf("%d\n", R - 1);
		}
		figura.clear();
	}
	return 0;
}
