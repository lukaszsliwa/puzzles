#include <cstdio>
using namespace std;

struct wektor {
	int x, y;
	wektor(int xx, int yy) : x(xx), y(yy) {}

};

int mod(int a, int b) {
	return a - b * (a / b);
}

int nwd(int a, int b) {
	while(b != 0) {
		int t = b;
		b = mod(b, a);
		a = t;
	}
	return a;
}

int nww(int a, int b) {
	return (a * b) / nwd(a, b);
}

bool skoczek(int a, int b, int x, int y) {
	int k[9];
	wektor u1(a, b), u2(-a, b), u3(a, -b), u4(-a, -b), 
		u5(b, a), u6(-b, a), u7(b, -a), u8(-b, -a);
	k[1] = nww(nww(u1.x, x), nww(u1.y, y));
	k[2] = nww(nww(u2.x, x), nww(u2.y, y));
	k[3] = nww(nww(u3.x, x), nww(u3.y, y));
	k[4] = nww(nww(u4.x, x), nww(u4.y, y));
	k[5] = nww(nww(u5.x, x), nww(u5.y, y));
	k[6] = nww(nww(u6.x, x), nww(u6.y, y));
	k[7] = nww(nww(u7.x, x), nww(u7.y, y));
	k[8] = nww(nww(u8.x, x), nww(u8.y, y));
	for(int i = 1; i <= 8; ++i)
		printf("k[%d] = %d\n", i, k[i]);
	return true;
}

main() {
	int n, a, b, x, y;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		printf(skoczek(a, b, x, y) ? "TAK\n" : "NIE\n");
	}
}
