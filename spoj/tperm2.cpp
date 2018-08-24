#include <iostream>
#include <algorithm>

std::string r;

int main() {
	int t, l;
	std::cin >> t;
	while(t--) {
		std::cin >> l;
		r = "";
		for(int i = 'a'; i < 'a' + l; ++i)
			r += char(i);
		std::cout << r << std::endl;
		while(std::next_permutation(r.begin(), r.end()))
			std::cout << r << std::endl;
	}
}
