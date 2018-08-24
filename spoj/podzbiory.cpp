//#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*namespace std {
	ostream& operator << (ostream& os, vector<int>& v) {
		for(int i = 0; i < v.size(); ++i)
			os << v[i] << " ";
		return os;
	}
}*/

vector<int> vec;

void sets(vector<int>& v, int val, int n, int p) {
	v.push_back(val);
	if(p == 0) {
		for(int i = 0; i < v.size(); ++i)
			printf("%d ", v[i]);
		printf("\n");
	}
	for(int i = val + 1; i <= n; ++i)
		sets(v, i, n, p - 1);
	v.pop_back();
}

int main() {
	int t, n, k;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; ++i)
			sets(vec, i, n, k - 1);
	}
}
