#include <iostream>
#include <algorithm>

long long int binos(int a, int b) {
	long long int S = 1, P = 1, l, m;
	for(l = 0; l < b; ++l)
		S *= (a - l);
	for(m = 1; m <= b; ++m)
		P *= m;
	return S / P;
}

int main() {
	int t, n, k;
	std::cin >> t;
	while(t--) {
		std::cin >> n >> k;
		std::cout << binos(n, std::min(k, n-k)) << std::endl;
	}
}
