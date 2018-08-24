#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> v;

main() {
	vector<int>::iterator i;
	int liczba, n, k, m, l;
	scanf("%d%d", &n, &k);
	while(n--) {
		scanf("%d", &liczba);
		v.push_back(liczba);
	}
	sort(v.begin(), v.end());
	for(i = v.begin() + 1, m = *(v.begin()) + k, l = 1; i != v.end(); ++i)
		if(*i >= m) {
			m = *i + k;
			l++;
		}
	printf("%d", l);
}
