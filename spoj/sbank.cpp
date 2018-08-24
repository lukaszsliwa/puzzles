#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct k {
	int a, b, c, d, e, f;
	k() { }
	k(int aa, int bb, int cc, int dd, int ee, int ff) {
		a = aa; b = bb; c = cc; d = dd; e = ee; f = ff;
	}
};

vector<k> w;

bool cmp(const k& a, const k& b) {
	return a.a < b.a || (a.a == b.a && a.b < b.b) ||
	(a.a == b.a && a.b == b.b && a.c < b.c) ||
	(a.a == b.a && a.b == b.b && a.c == b.c && a.d < b.d) ||
	(a.a == b.a && a.b == b.b && a.c == b.c && a.d == b.d && a.e < b.e) ||
	(a.a == b.a && a.b == b.b && a.c == b.c && a.d == b.d && a.e == b.e && a.f < b.f);
}

bool to_samo(const k& A, const k& B) {
	return A.a == B.a && A.b == B.b && A.c == B.c && 
		A.d == B.d && A.e == B.e && A.f == B.f;
}

void drukuj(int a, int p) {
	int i;
	if(a != 0)
		p -= ((int)floor(log10((double)a)) + 1);
	else
		p--;
	for(i = 0; i < p; ++i)
		printf("0");
	printf("%d ", a);
}

void wypisz(const k& K, int e) {
	drukuj(K.a, 2);
	drukuj(K.b, 8);
	drukuj(K.c, 4);
	drukuj(K.d, 4);
	drukuj(K.e, 4);
	drukuj(K.f, 4);
	printf("%d\n", e);
}

void wynik(vector<k>& q) {
	int i, r = 1;
	for(i = 1; i < q.size(); ++i) {
		if(to_samo(q[i - 1], q[i])) r++;
		else {
			wypisz(q[i - 1], r);
			r = 1;
		}
	}
	wypisz(q[q.size() - 1], r);
}

main() {
	int t, m, a, b, c, d, e, f;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &m);
		while(m--) {
			scanf("%d%d%d%d%d%d ", &a, &b, &c, &d, &e, &f);
			w.push_back(k(a, b, c, d, e, f));
		}
		sort(w.begin(), w.end(), cmp);
		wynik(w);
		w.clear();
		if(t != 0)
			printf("\n");
	}
}
