// PROG: moat
// LANG: C++
// ID: C++
//
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct wsp {
	int x, y;
	wsp(int xx, int yy) : x(xx), y(yy) { }
};

int n;
vector<wsp> w, stack;

typedef vector<wsp>::iterator vec_iter;

vec_iter p0;

void wczytaj() {
	FILE *in;
	int a, b;
	in = fopen("moat.in", "r");
	fscanf(in, "%d", &n);
	while(n--) {
		fscanf(in, "%d%d", &a, &b);
		w.push_back(wsp(a, b));	
	}
	fclose(in);
}

bool compare(const wsp& A, const wsp& B) {
	return A.x * B.y - A.y * B.x > 0;
}

bool kat(vec_iter a, vec_iter b, vec_iter c) {
	return (a->x - b->x) * (c->y - b->y) - (a->y - b->y) * (c->x - b->x) > 0;
}

double p(int x) {
	return (double)(x * x);
}

/*void wypisz(vector<wsp>& g) {
	for(vec_iter y = g.begin(); y < g.end(); ++y)
		printf("(%d ; %d)\n", y->x, y->y);
}*/

bool compare_p0(const wsp& A, const wsp& B) {
	return (A.x - p0->x) * (B.y - p0->y) - (A.y - p0->y) * (B.x - p0->x) > 0;
}

main() {
	FILE *out;
	double R = 0.0;
	wczytaj();
	sort(w.begin(), w.end(), compare);
	p0 = w.begin();
	sort(w.begin() + 1, w.end(), compare_p0);
	w.push_back(w[0]);
	stack.push_back(w[0]);
	stack.push_back(w[1]);
	stack.push_back(w[2]);
	for(vec_iter y = w.begin() + 3;
		y < w.end(); ++y) {
		while(kat(stack.end() - 2, stack.end() - 1, y))
			stack.pop_back();
		stack.push_back(wsp(y->x, y->y));
	}
	for(vec_iter y = stack.begin();
		y < stack.end() - 1; ++y) {
		R += (double)sqrt((double)(p((y + 1)->x - y->x) + (double)p((y + 1)->y - y->y)));
	}
	out = fopen("moat.out", "w");
	fprintf(out, "%.2lf\n", R);
	fclose(out);
}
