#include <algorithm>
#include <vector>
#include <list>
using namespace std;

struct kra {
	int w, wysokosc;
	kra(int ww, int wy) : w(ww), wysokosc(wy) {}
	bool operator < (const kra& K) const {
		return wysokosc > K.wysokosc;
	}
	kra& operator = (const kra& K) {
		w = K.w;
		wysokosc = K.wysokosc;
		return *this;
	}
};

const int n_max = 100001;
const int infty = 10000000;
int n, wysokosc[n_max], koszty[n_max];

vector<list<int> > graf;

inline void wczytaj() {
	int m, a, b;
	scanf("%d%d", &n, &m);
	graf.resize(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &wysokosc[i]);
		koszty[i] = infty;
	}
	while(m--) {
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
}

vector<kra> q;

void push(const kra& e) {
	q.push_back(e);
	push_heap(q.begin(), q.end());
}

kra pop() {
	kra t = q[0];
	pop_heap(q.begin(), q.end());
	q.pop_back();
	return t;
}

main() {
	wczytaj();
	koszty[1] = wysokosc[1];
	push(kra(1, wysokosc[1]));
	while(!q.empty()) {
		kra v = pop();
		for(list<int>::iterator y = graf[v.w].begin();
			y != graf[v.w].end(); ++y)
			if(koszty[*y] > max(koszty[v.w], wysokosc[*y])) {
				koszty[*y] = max(koszty[v.w], wysokosc[*y]);
				push(kra(*y, koszty[*y]));
			}
	}
	printf("%d\n", koszty[n]);
}
