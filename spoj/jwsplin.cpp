#include <iostream>

int main() {
	int xa, ya, xb, yb, xc, yc, t;
	std::cin >> t;
	while(t--) {
		std::cin >> xa >> ya >> xb >> yb >> xc >> yc;
		if(xa * yb + xb * yc + xc * ya - xc * yb - xb * ya - xa * yc == 0)
			std::cout << "TAK\n";
		else
			std::cout << "NIE\n";
	}
}
