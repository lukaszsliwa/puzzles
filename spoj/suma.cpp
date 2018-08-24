#include <iostream>

int main() {
	int v, s = 0;;
	while(std::cin >> v) {
		s += v;
		std::cout << s << std::endl;
	}
}
