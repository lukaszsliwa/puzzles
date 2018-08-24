#include <iostream>

int len = 0, tab[11];

void wrzuc(const int& e) {
	if(len == 10)
		std::cout << ":(\n";
	else {
		tab[++len] = e;
		std::cout << ":)\n";
	}
}

void wypisz() {
	if(len == 0)
		std::cout << ":(\n";
	else
		std::cout << tab[len--] << "\n";
}

int main() {
	char znak;
	while(std::cin >> znak) {
		if(znak == '+') {
			int liczba;
			std::cin >> liczba;
			wrzuc(liczba);
		} else if(znak == '-')
			wypisz();
	}
}
