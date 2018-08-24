#include <iostream>
#include <string>

std::string line;

int A[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
int B[] = { 0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192,
		208, 224, 240 };

int main() {
	while(std::cin >> line) {
		for(int i = 0; i < line.size(); i += 2)
			std::cout << (char)(A[line[i] - 'A'] + B[line[i + 1] - 'A']);
		std::cout << std::endl;
	}
}
