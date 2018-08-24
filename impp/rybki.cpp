#include <cstdio>
#include <vector>
using namespace std;

struct p {
	int a, b;
	p(int aa, int bb) : a(aa), b(bb) {}
};

vector<p> v;

int main() {
	int n, t, a, b;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &a, &b);
		v.push_back(p(a, b));
	}
	scanf("%d", &n);
	while(n--) {
		int nr, left, right;
		bool no = false;
		scanf("%d%d", &t, &nr); nr--;
		left = v[nr].a;
		right = v[nr].b;
		while(--t) {
			scanf("%d", &nr); nr--;
			if(v[nr].a > right || left > v[nr].b)
				no = true;
			else {
				left = max(left, v[nr].a);
				right = min(right, v[nr].b);
			}
		}
		if(no)
			printf("NIE\n");
		else 
			printf("%d %d\n", left, right);
	}
}
