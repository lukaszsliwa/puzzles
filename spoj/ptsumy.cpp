#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec;

void foo(vector<int>& v, int p, int aktS, int& S) {
	aktS += p;
	v.push_back(p);
	if(aktS == S) {
		for(int i = 0; i < v.size(); ++i)
			printf("%d ", v[i]);
		printf("\n");
	}
	for(int i = p; aktS + i <= S; ++i)
		foo(v, i, aktS, S);
	v.pop_back();
}

int main() {
	int t, suma;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &suma);
		for(int i = 1; i <= suma; ++i)
			foo(vec, i, 0, suma);
	}
}
