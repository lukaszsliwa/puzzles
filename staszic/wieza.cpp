#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll_int;

vector<ll_int> w;
ll_int e;

void wczytaj() {
	int n;
	ll_int l;
	scanf("%d%lld", &n, &e);
	while(n--) {
		scanf("%lld", &l);
		w.push_back(l);
	}
	sort(w.begin(), w.end());
}

int szukaj(int a, int b, ll_int szukaj) {
	int mid;
	while(a <= b) {
		mid = (a + b) / 2;
		if(w[mid] == szukaj)
			return mid;
		else if(w[mid] < szukaj)
			a = mid + 1;
		else
			b = mid - 1;
	}
	return b;
}

main() {
	int i, y;
	ll_int ile, wynik;
	wczytaj();
	ile = wynik = 1;
	for(i = 0; i < w.size(); ++i) {
		y = szukaj(i, w.size() - 1, w[i] + 2 * e);
		//printf("%lld %lld\n", w[i], w[y]);
		if(y - i + 1 > ile) {
			ile = y - i + 1;
			wynik = (w[i] + w[y]) / 2;
		}
	}
	printf("%lld %lld\n", wynik, ile);
}
