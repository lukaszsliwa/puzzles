#include <stdio.h>

const int n_max = 10001;
const int infty = 10000000;

class plonk {
	class para {
	public:
		int a, b;
		para() { }
		para(int aa, int bb) : a(aa), b(bb) { }
	} p[n_max];
	int value, wyniki[n_max];
public:
	plonk() {
		int t, n, m, a, b, i, y, q;
		t = getint();
		while(t--) {
			value = infty;
			n = getint();
			for(i = 0; i < n; ++i) {
				wyniki[i] = 0;
				p[i].a = getint();
				p[i].b = getint();
			}
			for(i = 0; i < n; ++i)
				for(y = i + 1; y < n; ++y)
					if(i != y) {
						wyniki[i] += (q = dist(p[y], p[i]));
						wyniki[y] += q;
					}
			for(i = 0; i < n; ++i)
				value = (wyniki[i] <? value);
			printf("%d\n", value);
		}
	}
	int getint() {
		char znak;
		int t;
		while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
		t = znak - '0';
		while((znak = getchar_unlocked()) && znak >= '0' && znak <= '9')
			t = t * 10 + znak - '0';
		return t;
	}
	int dist(const para& a, const para& b) {
		return ((a.a - b.a) < 0 ? -(a.a - b.a) : (a.a - b.a)) + ((a.b - b.b) < 0 ? -(a.b - b.b) : (a.b - b.b));
	}
};

main() {
	plonk p;
}
