#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	short int n, d, l;
	scanf("%hd", &n);
	while(n--) {
		vector<short int> p;
		scanf("%hd", &d);
		while(d--) {
			scanf("%hd", &l);
			p.push_back(l);
		}
		sort(p.begin(), p.end());
		short int maks = p.back();
		p.pop_back();
		printf("%hd ", maks);
		while(!p.empty() && p.back() == maks) {
			printf("%hd ", maks);
			p.pop_back();
		}
		for(vector<short int>::iterator i = p.begin();
			i < p.end(); ++i)
			printf("%hd ", *i);
		printf("\n");
	}
}
