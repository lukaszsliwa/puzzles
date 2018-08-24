#include <iostream>
#include <cmath>

int main() {
	long long int r, nr, m, l, k, s, zysk = 0;
	long long int c[101];
	std::cin >> m >> l >> k >> s;;
	for(int i = 1; i <= m; ++i)
		std::cin >> c[i];
	while(l--) {
		std::cin >> nr >> r;
		int ile_sal, modulo = r % k;
		if(modulo >= (int)floor((double)k / 2.0)) {
			ile_sal = (r / k) + 1;
			zysk += -(ile_sal * s) + r * c[nr];
		} else {
			ile_sal = r / k;
			zysk += -(ile_sal * s) + (r - modulo) * c[nr];
		}
	}
	std::cout << zysk << std::endl;
}
