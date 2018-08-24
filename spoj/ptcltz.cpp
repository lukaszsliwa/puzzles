#include <iostream>
using namespace std;

int t, n, s, x;

int main() {
	cin >> t;
	while(t--) {
		cin >> s;
		n = 1;
		x = s;
		while(x != 1) {
			(x % 2 == 0) ? x /= 2 : x = 3 * x + 1;
			n++;
		}
		cout << (n - 1) << endl;
	}
}
