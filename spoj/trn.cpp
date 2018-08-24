#include <iostream>

int tab[201][201];

int main() {
	int a, b;
	std::cin >> a >> b;
	for(int i = 0; i < a; ++i)
		for(int y = 0; y < b; ++y)
			std::cin >> tab[i][y];
	for(int i = 0; i < b; ++i) {
		for(int y = 0; y < a; ++y)
			std::cout << tab[y][i] << " ";
		std::cout << std::endl;
	}
}
