#include <iostream>
#include <sstream>
#include <string>

std::string text;

int main() {
	while(std::getline(std::cin, text)) {
		std::istringstream is(text);
		is >> text;
		std::cout << text;
		while(is >> text) {
			text[0] = toupper(text[0]);
			std::cout << text;
		}
		std::cout << std::endl;
	}
}
