#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll_int;

struct wsp {
	ll_int x, y;
	wsp() { }
	wsp(ll_int xx, ll_int yy) {
		x = xx;
		y = yy;
	}
};

vector<wsp> cebulka, stack, tmp;
typedef vector<wsp>::iterator vec_iter;

vec_iter p0;

void wczytaj() {
	int n;
	ll_int x, y;
	scanf("%d", &n);
	while(n--) {
		scanf("%lld%lld", &x, &y);
		cebulka.push_back(wsp(x, y));
	}
}

bool min_pkt(const wsp& A, const wsp& B) {
	return A.x * B.y - A.y * B.x > 0; 
}

bool cmp(const wsp& A, const wsp& B) {
	return (A.x - p0->x) * (B.y - p0->y) - (A.y - p0->y) * (B.x - p0->x) > 0;
}

ll_int kat(vec_iter a, vec_iter b, vec_iter c) {
	return (a->x - b->x) * (c->y - b->y) - (a->y - b->y) * (c->x - b->x);
}

void graham() {
	vec_iter y;
	stack.push_back(cebulka[0]);
	stack.push_back(cebulka[1]);
	stack.push_back(cebulka[2]);
	for(y = cebulka.begin() + 3; y != cebulka.end(); ++y) {
		while(!stack.empty() && kat(stack.end() - 2, stack.end() - 1, y) >= 0) {
			tmp.push_back(wsp(stack.back().x, stack.back().y));
			stack.pop_back();
		}
		stack.push_back(wsp(y->x, y->y));
	}
}

main() {
	int R = 0;
	wczytaj();
	while(!cebulka.empty() && cebulka.size() > 3) {
		sort(cebulka.begin(), cebulka.end(), min_pkt);
		p0 = cebulka.begin();
		sort(cebulka.begin() + 1, cebulka.end(), cmp);
		graham();
		cebulka.clear();
		stack.clear();
		while(!tmp.empty()) {
			cebulka.push_back(wsp(tmp.back().x, tmp.back().y));
			tmp.pop_back();
		}
		R++;
	}
	if(cebulka.size() != 0 && cebulka.size() <= 3)
		R++;
	printf("%d\n", R);
}
