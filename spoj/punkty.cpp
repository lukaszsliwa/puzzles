#include <cstdio>
using namespace std;

struct Punkt {
	int x, y;
	Punkt() {}
	Punkt(int xx, int yy) : x(xx), y(yy) {}
	bool zero() {
		return x == 0 && y == 0;
	}
};

#define punkt(x, y) scanf("%d%d", &x, &y)

bool wczytaj(Punkt& p1, Punkt& p2, Punkt& p3, Punkt& p) {
	punkt(p1.x, p1.y);
	punkt(p2.x, p2.y);
	punkt(p3.x, p3.y);
	punkt(p.x, p.y);
	return p1.zero() && p2.zero() 
		&& p3.zero() && p.zero();
}

int abs(int a) {
	return a < 0 ? -a : a;
}

int licz(Punkt& a, Punkt& b, Punkt& c) {
	return abs(a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - a.x * c.y - b.x * a.y);
}

int main() {
	int pole1, pole2, pole3, pole;
	Punkt p1, p2, p3, p;
	while(!wczytaj(p1, p2, p3, p)) {
		pole1 = licz(p1, p, p2);
		pole2 = licz(p2, p, p3);
		pole3 = licz(p3, p, p1);
		pole = licz(p1, p2, p3);
		//printf("%d %d %d %d\n", pole1, pole2, pole3, pole);
		if((pole1 == 0 || pole2 == 0 || pole3 == 0) &&
			(pole1 + pole2 + pole3 == pole))
			printf("E\n");
		else if(pole1 + pole2 + pole3 == pole)
			printf("I\n");
		else
			printf("O\n");
	}
}
