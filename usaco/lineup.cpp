// PROG: lineup
// LANG: C++
// ID: C++
#include <cstdio>
#include <queue>

using namespace std;

const int N_MAX = 5001;
long long int tab[N_MAX], n;

struct l {
	long long int pozycja, liczba, ile;
	l(long long int pp, long long int ll, long long int ii) {
		pozycja = pp;
		liczba = ll;
		ile = ii;
	}
	bool operator <(const l& L) const {
		return ile < L.ile;
	}
};

priority_queue<l> q;

inline void wczytaj() {
	int i;
	FILE *in;
	in = fopen("lineup.in", "r");
	fscanf(in, "%lld", &n);
	for(i = 0; i < n; ++i)
		fscanf(in, "%lld", &tab[i]);
	fclose(in);
}

long long int max(long long int a, long long int b) {
	return a < b ? b : a;
}

main() {
	FILE *out;
	long long int p, li, i, y, R = 0;
	wczytaj();
	q.push(l(0, tab[0], 1));
	while(!q.empty()) {
		p = q.top().pozycja;
		li = q.top().liczba;
		i = q.top().ile;
		R = max(R, i);
		q.pop();
		for(y = p + 1; y < n; ++y)
			if(li < tab[y])
				q.push(l(y, tab[y], i + 1));
	}
	out = fopen("lineup.out", "w");
	fprintf(out, "%lld\n", R);
	fclose(out);
}
