#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<std::string> bit;

typedef vector<std::string>::iterator vec_iter;

int main() {
	int c, n, k, d;
	cin >> c;
	while(c--) {
		cin >> n >> k >> d;

		std::string v;
		
		bit.push_back(v);
		while(next_permutation(v.begin(), v.end())) {
			bit.push_back(v);
		}
		sort(bit.begin(), bit.end());
		for(vec_iter it = bit.begin(); it != bit.end(); ++it)
			cout << *it << ' ';
	}
}
