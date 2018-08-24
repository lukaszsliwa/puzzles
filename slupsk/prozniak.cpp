#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int i, n, m, komnata;
vector< set<int> > zamek;

int main() {
	scanf("%d%d", &n, &m);
	zamek.resize(n + 1);
	for(i = 1; i <= m; ++i) {
		scanf("%d", &komnata);
		zamek[komnata].insert(i);
	}
	for(i = 1; i <= n; ++i) {
		printf("%d", zamek[i].size());
		for(set<int>::const_iterator y = zamek[i].begin();
			y != zamek[i].end(); ++y)
			printf(" %d", *y);
		printf("\n");
	}
	return 0;
}
