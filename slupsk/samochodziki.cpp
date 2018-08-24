#include <cstdio>
#include <queue>

using namespace std;

const int N_MAX = 100001;
const int P_MAX = 500001;
const int infty = 100000000;
struct s {
	int sam, czas;
	s(int ss, int cc) : sam(ss), czas(cc) { }
	bool operator < (const s& K) const {
		return czas < K.czas;
	}
};

int n, k, p;
int tab[P_MAX], czas[P_MAX], tmp[N_MAX];
bool jest[N_MAX];

priority_queue<s> Q;

void wczytaj() {
	int i;
	scanf("%d%d%d", &n, &k, &p);
	for(i = 1; i <= p; ++i) {
		scanf("%d", &tab[i]);
		czas[i] = infty;
	}
	for(i = 0; i <= n; ++i) {
		tmp[i] = infty;
		jest[i] = false;
	}
	for(i = p; i >= 1; --i) {
		czas[i] = tmp[tab[i]];
		tmp[tab[i]] = i;
	}
}

int main() {
	int i, sam, size = 0, R = 0;
	wczytaj();
	for(i = 1; i <= p; ++i) {
		sam = tab[i];
		if(!jest[sam]) {
			if(size < k)
				size++;
			else {
				jest[Q.top().sam] = false;
				Q.pop();
			}
			Q.push(s(sam, czas[i]));
			jest[sam] = true;
			R++;
		} else
			Q.push(s(sam, czas[i]));
	}
	printf("%d", R);
	return 0;
}
