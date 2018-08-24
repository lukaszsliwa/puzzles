#include <cstdio>
using namespace std;

typedef long long int llint;

inline llint input() {
	llint t;
	char znak;
	while((znak = getchar_unlocked()) &&
		(znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) &&
		(znak >= '0' && znak <= '9'))
		t = t * 10 + znak - '0';
	return t;
}

inline int power(llint v, llint p) {
	llint result = 1;
	while(p > 0) {
		if(p % 2)
			result = (result * v) % 10;
		v = (v * v) % 10;
		p /= 2;
	}
	return result;
}

int main() {
	llint t = input();
	while(t--) {
		llint v = input(), p = input();
		printf("%d\n", power(v, p));
	}
}
