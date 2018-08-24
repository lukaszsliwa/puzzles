#include <iostream>

int main() {
	int t, m, l, s;
	std::cin >> t;
	while(t--) {
		std::cin >> m;
		s = 0;
		while(m--) {
			std::cin >> l;
			s += l;
		}
		std::cout << s << std::endl;
	}
}
