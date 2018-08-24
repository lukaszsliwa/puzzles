#include <iostream>
#include <string>

int t, tab['z' + 1];

std::string row;

int main() {
	std::cin >> t;
	while(std::getline(std::cin, row))
		for(int i = 0; i < row.length(); ++i)
			tab[row[i]]++;
	for(int i = 'a'; i <= 'z'; ++i)
		if(tab[i] != 0)
			std::cout << char(i) << " " << tab[i] << std::endl;
	for(int i = 'A'; i <= 'Z'; ++i)
		if(tab[i] != 0)
			std::cout << char(i) << " " << tab[i] << std::endl;
}
