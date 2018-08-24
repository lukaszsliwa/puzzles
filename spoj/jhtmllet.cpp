#include <iostream>
#include <string>

std::string text;

int main() {
	while(std::getline(std::cin, text)) {
		bool start = false;
		for(int i = 0; i < text.length(); ++i) {
			if(text[i] == '<' || (text[i - 1] == '<' && text[i] == '/'))
				start = true;
			else if(text[i] == '>')
				start = false;
			if(start)
				text[i] = toupper(text[i]);
			std::cout << text[i];
		}
		std::cout << std::endl;
	}
}
