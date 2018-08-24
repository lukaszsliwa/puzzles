#include <cstdio>
#include <algorithm>
using namespace std;

class ogrod {
	struct kwiat {
		int nr;
		long long int x, y;
		short kwiatek; 
		/* 0 - nieokreslony, 1 - gozdzik, 2 - roza */
		kwiat(int nn, llint xx, llint yy) {
			nr = nn;
			x = xx;
			y = yy;
			roza = 0;
		}
	};
	vector<kwiat> w;
public:
	ogrod() {
		int n, nr = 1;
		llint x, y;
		scanf("%d", &n);
		while(nr <= n) {
			scanf("%lld%lld", &x, &y);
			w.push_back(kwiat(nr++, x, y));
		}
		sort(w.begin(), w.end(), cmp1);
		
	}
	bool cmp1(const kwiat& A, const kwiat& B) {
		return A.y < B.y || A.y == B.y && A.x < B.x;
	}
	bool cmp2(const kwiat& A, const kwiat& B) {
		return A.x < B.x || A.x == B.x && A.y < B.y;
	}
	bool cmp3(const kwiat& A, const kwiat& B) {
		return A.nr < B.nr;
	}
	~ogrod() {
		
	}
};

main() {
	ogrod o;
}
