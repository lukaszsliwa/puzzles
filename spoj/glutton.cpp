#include <cstdio>
using namespace std;

typedef long long int llint;

inline void input(llint& v) {
	char znak;
	while((znak = getchar_unlocked()) && 
		(znak < '0' || znak > '9'));
	v = znak - '0';
	while((znak = getchar_unlocked()) &&
		znak >= '0' && znak <= '9')
		v = v * 10 + znak - '0';
}

int main() {
	llint t;
	input(t);
	while(t--) {
		llint n, pak, suma = 0;
		input(n); input(pak);
		while(n--) {
			llint p;
			input(p);
			suma += (86400 / p);
		}
		if(suma % pak == 0)
			printf("%d\n", suma / pak);
		else
			printf("%d\n", (suma / pak) + 1);
	}
}
