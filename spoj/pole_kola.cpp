#include <cstdio>
using namespace std;

#define pi 3.141592654
#define pole(r, d) pi * (r - 0.5 * d) * (r + 0.5 * d)

int main() {
	double r, d;
	scanf("%lf %lf", &r, &d);
	printf("%.2lf\n", pole(r, d));
}
