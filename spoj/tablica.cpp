#include <iostream>
#include <vector>

std::vector<int> w;

int main() {
	int v;
	while(std::cin >> v)
		w.push_back(v);
	while(!w.empty()) {
		std::cout << w.back() << " ";
		w.pop_back();
	}
}
