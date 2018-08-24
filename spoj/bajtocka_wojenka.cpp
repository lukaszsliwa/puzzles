#include <iostream>
using namespace std;

int tab[53];

bool mniejsza(int i) {
	for(int l = i - 1; l > 0; --l) {
		if(tab[l] == 1) {
			tab[l] = 0;
			cout << i << " "<< l << endl;
			return true;
		}
	}
	return false;
}

int main() {
	int l, t = 26, R = 0;
	for(int i = 1; i <= 26; ++i)
		tab[i] = 1;
	while(t--) {
		cin >> l;
		tab[l] = 2;
	}
	for(int i = 1; i <= 52; ++i)
		if(tab[i] == 2) {
			if(mniejsza(i))
				R++;
		}
	cout << R << endl;
}
