#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll_int;

struct kolumna {
	ll_int x, y, r;
	kolumna() { }
	kolumna(ll_int xx, ll_int yy, ll_int rr) {
		x = xx;
		y = yy;
		r = rr;
	}
};

bool operator < (const kolumna& A, const kolumna& B) {
	return A.x * B.y - A.y * B.x > 0;
}

vector<kolumna> swiatynia;
typedef vector<kolumna>::iterator vec_iter;

void wczytaj() {
	ll_int n, x, y, r;
	scanf("%lld", &n);
	while(n--) {
		scanf("%lld%lld%lld", &x, &y, &r);
		swiatynia.push_back(kolumna(x, y, r));
	}
}

bool nakladaja_sie(vec_iter a, vec_iter b) {
	return (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) < (a->r + b->r) * (a->r + b->r);	
}

bool odpowiedz() {
	vec_iter a = swiatynia.begin(), b = a + 1;
	while(b < swiatynia.end()) {
		if(nakladaja_sie(a, b))
			return true;
		b = ++a + 1;
	}
	if(nakladaja_sie(swiatynia.end() - 1, swiatynia.begin()))
		return true;
	return false;
}

void wypisz(vector<kolumna>& g) {
	for(vec_iter q = g.begin(); q < g.end(); ++q)
		printf("[%lld ; %lld] ", q->x, q->y);
}

int main() {
	wczytaj();
	sort(swiatynia.begin(), swiatynia.end());
	//wypisz(swiatynia);
	printf(odpowiedz() ? "TAK\n" : "NIE\n");
	return 0;
}
