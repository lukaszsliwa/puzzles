#include <iostream>

std::string row;

int main() {
	while(std::getline(std::cin, row)) {
		for(int i = 0; i < row.length(); ++i) {
			if(row[i] >= 'A' && row[i] <= 'Z') {
				row[i] += 3;
				if(row[i] > 'Z')
					row[i] = 'A' + row[i] - 'Z' - 1;
			}
			std::cout << row[i];
		}
		std::cout << std::endl;
	}
}
