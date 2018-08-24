/*
PROG: asteroid
LANG: C++
ID: 3crhash1
*/
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct wsp {
	int x, y;
	wsp(int xx, int yy ) {
		x = xx;
		y = yy;
	}
};

vector<wsp> S;

bool sort1(const wsp& A, const wsp& B) {
	return A.x == B.x || A.y == B.y;
}

main() {
	int n, m, x, y, R = 0;
	ifstream in ("asteroid.in");
	//scanf("%d%d", &n, &m);
	in >> n >> m;
	while(m--) {
	//	scanf("%d%d", &x, &y);
		in >> x >> y;
		S.push_back(wsp(x, y));
	}
	sort(S.begin(), S.end(), sort1);
	for(vector<wsp>::const_iterator y = S.begin() + 1;
		y < S.end(); ++y)
		if(y->x == (y - 1)->x || y->y == (y - 1)->y)
			R++;
	//printf("%d\n", R);
	ofstream out("asteroid.out");
	out << R << endl;
}
